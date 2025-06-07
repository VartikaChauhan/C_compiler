%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbol_table.h"
#include "semantic.h"

int yylex();
void yyerror(const char *s);
%}

%union {
    int ival;
    char *sval;
    struct ASTNode *node;
}

%token <sval> IDENTIFIER
%token <ival> NUMBER
%token INT RETURN
%token EQ NE LE GE
%token LPAREN RPAREN LBRACE RBRACE COMMA SEMICOLON ASSIGN PLUS MINUS MUL DIV

%type <node> program func_decl stmt expr
%type <ival> param_list arg_list

%%

program:
      func_decl         { evaluate($1); }
    | stmt              { evaluate($1); }
    ;

func_decl:
    INT IDENTIFIER LPAREN param_list RPAREN SEMICOLON {
        /* Declare the function – for simplicity, we assume the return type is always int */
        char paramTypes[100][10];
        for (int i = 0; i < $4; i++) {
            strcpy(paramTypes[i], "int");
        }
        if (!insertFunction($2, "int", paramTypes, $4)) {
            yyerror("Function already declared.");
        }
        $$ = createLeaf($2);
    }
    ;

param_list:
      INT IDENTIFIER {
           insertSymbol($2, "int");
           $$ = 1;
      }
    | param_list COMMA INT IDENTIFIER {
           insertSymbol($4, "int");
           $$ = $1 + 1;
      }
    | /* empty */ {
           $$ = 0;
      }
    ;

stmt:
      INT IDENTIFIER SEMICOLON {
           if (!insertSymbol($2, "int")) {
              yyerror("Variable already declared.");
           }
           $$ = createNode("DECL", createLeaf($2), NULL);
      }
    | IDENTIFIER ASSIGN expr SEMICOLON {
           if (!isDeclared($1)) {
              yyerror("Variable not declared.");
           }
           $$ = createNode("ASSIGN", createLeaf($1), $3);
      }
    | RETURN expr SEMICOLON {
           $$ = createNode("RETURN", $2, NULL);
      }
    | IDENTIFIER LPAREN arg_list RPAREN SEMICOLON {
           if (!isFunctionDeclared($1)) {
              yyerror("Function not declared.");
           }
           if (!validateFunctionCall($1, $3)) {
              yyerror("Invalid number of arguments.");
           }
           $$ = createNode("CALL", createLeaf($1), NULL);
      }
    ;

arg_list:
      expr { $$ = 1; }
    | arg_list COMMA expr { $$ = $1 + 1; }
    | /* empty */ { $$ = 0; }
    ;

expr:
      NUMBER { $$ = createLeafInt($1); }
    | IDENTIFIER { 
           if (!isDeclared($1)) {
              yyerror("Variable not declared.");
           }
           $$ = createLeaf($1);
      }
    | expr PLUS expr  { $$ = createNode("+", $1, $3); }
    | expr MINUS expr { $$ = createNode("-", $1, $3); }
    | expr MUL expr   { $$ = createNode("*", $1, $3); }
    | expr DIV expr   { $$ = createNode("/", $1, $3); }
    | expr EQ expr    { $$ = createNode("==", $1, $3); }
    | expr NE expr    { $$ = createNode("!=", $1, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
}

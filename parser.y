%{ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbol_table.h"
#include "semantic.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;

void yyerror(const char *s);
ASTNode* root;
%}

%union {
    int intval;
    char* strval;
    ASTNode* node;
}

// Keywords and tokens with semantic types
%token <strval> IDENTIFIER
%token <intval> NUMBER

%token INT RETURN IF ELSE WHILE
%token ASSIGN EQ NEQ LT GT LE GE
%token PLUS MINUS MUL DIV
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

// Nonterminals with semantic types
%type <node> stmt expr stmt_list decl assign return_stmt func_def program
%type <intval> param_list

%%

program:
      func_def                     { root = $1; semantic_check(root); }
    | stmt                         { root = $1; semantic_check(root); }
    ;

func_def:
    INT IDENTIFIER LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        char paramTypes[10][10];  
        for (int i = 0; i < $4; i++) {
            strcpy(paramTypes[i], "int");
        }
        if (!insertFunction($2, "int", paramTypes, $4)) {
            yyerror("Function already declared.");
        }
        $$ = createNode("FUNC", createLeaf($2), $7); // FUNC(name, body)
    }
    ;

param_list:
      /* empty */                  { $$ = 0; }
    | INT IDENTIFIER              { insertSymbol($2, "int"); $$ = 1; }
    | param_list COMMA INT IDENTIFIER {
                                    insertSymbol($4, "int");
                                    $$ = $1 + 1;
                                  }
    ;

stmt_list:
      stmt                         { $$ = $1; }
    | stmt_list stmt               { $$ = createNode("SEQ", $1, $2); }
    ;

stmt:
      decl                         { $$ = $1; }
    | assign                       { $$ = $1; }
    | return_stmt                  { $$ = $1; }
    ;

decl:
    INT IDENTIFIER SEMICOLON {
        if (!insertSymbol($2, "int")) {
            yyerror("Variable redeclared.");
        }
        $$ = createNode("DECL", createLeaf($2), NULL);
    }
    ;

assign:
    IDENTIFIER ASSIGN expr SEMICOLON {
        ASTNode* id = createLeaf($1);
        $$ = createNode("ASSIGN", id, $3);
    }
    ;

return_stmt:
    RETURN expr SEMICOLON {
        $$ = createNode("RETURN", $2, NULL);
    }
    ;

expr:
      expr PLUS expr               { $$ = createNode("+", $1, $3); }
    | expr MINUS expr              { $$ = createNode("-", $1, $3); }
    | expr MUL expr                { $$ = createNode("*", $1, $3); }
    | expr DIV expr                { $$ = createNode("/", $1, $3); }
    | LPAREN expr RPAREN           { $$ = $2; }
    | IDENTIFIER                   { $$ = createLeaf($1); }
    | NUMBER                       {  char buf[32];sprintf(buf, "%d", $1); $$ = createNode("num", NULL, NULL); $$->name = strdup(buf);}
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
}


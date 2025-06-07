%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

DIGIT   [0-9]
ID      [a-zA-Z_][a-zA-Z0-9_]*

%%
"int"                { return INT; }
"return"             { return RETURN; }
"=="                 { return EQ; }
"!="                 { return NE; }
"<="                 { return LE; }
">="                 { return GE; }
{DIGIT}+             { yylval.ival = atoi(yytext); return NUMBER; }
{ID}                 { yylval.sval = strdup(yytext); return IDENTIFIER; }
"("                  { return LPAREN; }
")"                  { return RPAREN; }
"{"                  { return LBRACE; }
"}"                  { return RBRACE; }
","                  { return COMMA; }
";"                  { return SEMICOLON; }
"="                  { return ASSIGN; }
"+"                  { return PLUS; }
"-"                  { return MINUS; }
"*"                  { return MUL; }
"/"                  { return DIV; }
[ \t\r\n]+           { /* ignore whitespace */ }
.                    { printf("Unknown character: %s\n", yytext); }
%%

int yywrap(){
    return 1;
}

%{
#include "ast.h"
#include "parser.tab.h"
#include <string.h>
%}

%%
"int"           { return INT; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }

[0-9]+          { yylval.intval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval.strval = strdup(yytext);
                    return IDENTIFIER;
                }

"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LE; }
">="            { return GE; }
"<"             { return LT; }
">"             { return GT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMICOLON; }
","             { return COMMA; }

[ \t\r\n]+      { /* skip whitespace */ }
"//".*          { /* skip single line comment */ }
"/*"([^*]|\*+[^*/])*\*+"/"   { /* skip multi-line comment */ }

.               { printf("Unknown character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}


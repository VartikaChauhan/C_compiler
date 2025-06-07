#include <stdio.h>

extern int yyparse();

int main() {
    printf("Enter C code for compilation:\n");
    yyparse();
    return 0;
}

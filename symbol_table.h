#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

int insertSymbol(char* name, const char* type);
int isDeclared(char* name);

int insertFunction(char* name, const char* returnType, char paramTypes[][10], int paramCount);
int isFunctionDeclared(char* name);
int validateFunctionCall(char* name, int argCount);

#endif

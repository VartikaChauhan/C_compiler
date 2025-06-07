#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_FUNCTIONS 50

typedef struct {
    char name[100];
    char type[20];
} Symbol;

typedef struct {
    char name[100];
    char returnType[20];
    char paramTypes[10][10];
    int paramCount;
} Function;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

Function functionTable[MAX_FUNCTIONS];
int functionCount = 0;

int insertSymbol(char* name, const char* type) {
    for(int i = 0; i < symbolCount; i++){
        if(strcmp(symbolTable[i].name, name) == 0)
            return 0; // already declared
    }
    strcpy(symbolTable[symbolCount].name, name);
    strcpy(symbolTable[symbolCount].type, type);
    symbolCount++;
    return 1;
}

int isDeclared(char* name) {
    for(int i = 0; i < symbolCount; i++){
        if(strcmp(symbolTable[i].name, name) == 0)
            return 1;
    }
    return 0;
}

int insertFunction(char* name, const char* returnType, char paramTypes[][10], int paramCount) {
    for (int i = 0; i < functionCount; i++){
        if(strcmp(functionTable[i].name, name) == 0)
            return 0; // function already declared
    }
    strcpy(functionTable[functionCount].name, name);
    strcpy(functionTable[functionCount].returnType, returnType);
    functionTable[functionCount].paramCount = paramCount;
    for (int i = 0; i < paramCount; i++){
        strcpy(functionTable[functionCount].paramTypes[i], paramTypes[i]);
    }
    functionCount++;
    return 1;
}

int isFunctionDeclared(char* name) {
    for (int i = 0; i < functionCount; i++){
        if(strcmp(functionTable[i].name, name) == 0)
            return 1;
    }
    return 0;
}

int validateFunctionCall(char* name, int argCount) {
    for (int i = 0; i < functionCount; i++){
        if(strcmp(functionTable[i].name, name) == 0){
            return (functionTable[i].paramCount == argCount);
        }
    }
    return 0;
}

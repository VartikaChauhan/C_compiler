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

static Symbol symbolTable[MAX_SYMBOLS];
static int symbolCount = 0;

static Function functionTable[MAX_FUNCTIONS];
static int functionCount = 0;

int insertSymbol(const char* name, const char* type) {
    for(int i = 0; i < symbolCount; i++){
        if(strcmp(symbolTable[i].name, name) == 0){
            printf("[Symbol Table] Symbol '%s' already declared.\n", name);
            return 0; // already declared
            }
    }
    if(symbolCount >= MAX_SYMBOLS){
          fprintf(stderr,"Symbol table full!\n");
          return 0;
    }
    strcpy(symbolTable[symbolCount].name, name);
    strcpy(symbolTable[symbolCount].type, type);
    symbolCount++;
     printf("[Symbol Table] Inserted symbol '%s' of type '%s'.\n", name, type);
    return 1;
}

int isDeclared(const char* name) {
    printf("[isDeclared] Looking for: '%s'\n", name);
    for(int i = 0; i < symbolCount; i++){
        if(strcmp(symbolTable[i].name, name) == 0){
            printf("[isDeclared] Found '%s'\n", name);
            return 1;
        }
    }
    printf("[isDeclared] Not found '%s'\n", name);
    return 0;
}

int insertFunction(const char* name, const char* returnType, char paramTypes[][10], int paramCount) {
    for (int i = 0; i < functionCount; i++){
        if(strcmp(functionTable[i].name, name) == 0){
            printf("[Symbol Table] Function '%s' already declared.\n", name);
            return 0; // function already declared
          }
    }
    if (functionCount >= MAX_FUNCTIONS) {
        fprintf(stderr, "Function table full!\n");
        return 0;
    }
    strcpy(functionTable[functionCount].name, name);
    strcpy(functionTable[functionCount].returnType, returnType);
    functionTable[functionCount].paramCount = paramCount;
    for (int i = 0; i < paramCount; i++){
        strcpy(functionTable[functionCount].paramTypes[i], paramTypes[i]);
    }
    functionCount++;
    printf("[Symbol Table] Inserted function '%s' with %d params.\n", name, paramCount);
    return 1;
}

int isFunctionDeclared(const char* name) {
    for (int i = 0; i < functionCount; i++) {
        if (strcmp(functionTable[i].name, name) == 0) {
            printf("[isFunctionDeclared] Found function '%s'\n", name);
            return 1;
        }
    }
    printf("[isFunctionDeclared] Not found function '%s'\n", name);
    return 0;
}

int validateFunctionCall(const char* name, int argCount) {
    for (int i = 0; i < functionCount; i++){
        if(strcmp(functionTable[i].name, name) == 0){
            return (functionTable[i].paramCount == argCount);
        }
    }
    return 0;
}


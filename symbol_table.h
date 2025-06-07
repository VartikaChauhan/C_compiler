#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

// Insert a new variable symbol. Returns 1 if successful, 0 if already declared.
int insertSymbol(const char* name, const char* type);

// Check if a variable has been declared. Returns 1 if declared, 0 otherwise.
int isDeclared(const char* name);

// Insert a new function declaration. Returns 1 if successful, 0 if already declared.
int insertFunction(const char* name, const char* returnType, char paramTypes[][10], int paramCount);

// Check if a function has been declared. Returns 1 if declared, 0 otherwise.
int isFunctionDeclared(const char* name);

// Validate a function call against its declaration (name and number of arguments).
// Returns 1 if valid, 0 otherwise.
int validateFunctionCall(const char* name, int argCount);

#endif // SYMBOL_TABLE_H


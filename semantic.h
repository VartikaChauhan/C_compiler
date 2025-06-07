#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"
#include "symbol_table.h"

// Perform semantic checks on the AST
void check_semantics(ASTNode* root);

typedef enum {
    TYPE_INT,
    TYPE_VOID,
    TYPE_ERROR
} Type;


// Perform type checking for a given AST node
Type type_check(ASTNode* node);

// Validate all function declarations and calls
void validate_functions(ASTNode* root);

#endif // SEMANTIC_H

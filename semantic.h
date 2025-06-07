#ifndef SEMANTIC_H 
#define SEMANTIC_H

#include "ast.h"
#include "symbol_table.h"

<<<<<<< HEAD
typedef enum {
    TYPE_INT,
    TYPE_VOID,
    TYPE_ERROR
} Type;

// Perform type checking for a given AST node
Type type_check(ASTNode* node);

// Perform semantic checks on the AST
void check_semantics(ASTNode* root);

// Validate all function declarations and calls
void validate_functions(ASTNode* root);
=======
// Entry point to perform semantic checks on the AST
void semantic_check(ASTNode* root);

// Utility function to report semantic errors
void semantic_error(const char* msg, ASTNode* node);
>>>>>>> b948ab8 (Added semantic analysis and function declaration validation)

#endif // SEMANTIC_H


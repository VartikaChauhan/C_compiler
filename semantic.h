#ifndef SEMANTIC_H 
#define SEMANTIC_H

#include "ast.h"
#include "symbol_table.h"


// Perform semantic checks on the AST
void semantic_check(ASTNode* root);

// Utility function to report semantic errors
void semantic_error(const char* msg, ASTNode* node);


#endif // SEMANTIC_H


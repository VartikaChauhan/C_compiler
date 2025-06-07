#include "ast.h"
#include "symbol_table.h"
#include <stdio.h>

void semantic_check(ASTNode* node) {
    if (!node) return;
    // Insert additional semantic validation if desired.
    semantic_check(node->left);
    semantic_check(node->right);
}

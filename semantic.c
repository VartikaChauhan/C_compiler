#include "ast.h"
#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declaration
void semantic_check(ASTNode* node);

void semantic_error(const char* msg, ASTNode* node) {
    fprintf(stderr, "Semantic error: %s\n", msg);
    // Optionally print node info for debugging
    if (node && node->op) {
        fprintf(stderr, " At node: %s\n", node->op);
    }
}

void semantic_check(ASTNode* node) {
    if (!node) return;

    printf("[Semantic Check] Visiting node op: %s, name: %s\n", 
            node->op ? node->op : "NULL", 
            node->name ? node->name : "NULL");

    // Check declaration nodes
    if (strcmp(node->op, "DECL") == 0) {
        // Variable declaration already handled during insertion,
        // but you can double-check here if needed
    }

    // Check assignment: variable must be declared
    else if (strcmp(node->op, "ASSIGN") == 0) {
        if (node->left && !isDeclared(node->left->name)) {
            semantic_error("Assignment to undeclared variable", node->left);
        }
    }

    // Check variable usage
    else if (strcmp(node->op, "id") == 0) {
    // Check if node->name is numeric
    char *endptr;
    strtol(node->name, &endptr, 10);
    if (*endptr == '\0') {
        // It's a number, so no undeclared variable error
    } else {
        if (!isDeclared(node->name) && !isFunctionDeclared(node->name)) {
            semantic_error("Use of undeclared variable or function", node);
        }
    }
}
    // Check function calls
    else if (strcmp(node->op, "CALL") == 0) {
        if (!isFunctionDeclared(node->left->name)) {
            semantic_error("Call to undeclared function", node->left);
        }
      }


    // Recursively check children
    semantic_check(node->left);
    semantic_check(node->right);
}





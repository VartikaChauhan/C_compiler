#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* createNode(char *op, ASTNode *left, ASTNode *right) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->op = strdup(op);
    node->left = left;
    node->right = right;
    node->name = NULL;
    node->value = 0;
    return node;
}

ASTNode* createLeaf(char *name) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->op = strdup("id");
    node->name = strdup(name);
    node->left = node->right = NULL;
    node->value = 0;
    return node;
}

ASTNode* createLeafInt(int value) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->op = strdup("num");
    node->value = value;
    node->left = node->right = NULL;
    node->name = NULL;
    return node;
}

void printAST(ASTNode* node, int level) {
    if(!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    if(strcmp(node->op, "id") == 0)
        printf("%s: %s\n", node->op, node->name);
    else if(strcmp(node->op, "num") == 0)
        printf("%s: %d\n", node->op, node->value);
    else
        printf("%s\n", node->op);
    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
}

void evaluate(ASTNode* node) {
    printf("AST Structure:\n");
    printAST(node, 0);
}

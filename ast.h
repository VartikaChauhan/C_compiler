#ifndef AST_H
#define AST_H

typedef struct ASTNode {
    char *op;            // operator or type indicator ("id", "num", etc.)
    char *name;          // for identifier nodes
    int value;           // for number nodes
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode* createNode(char *op, ASTNode *left, ASTNode *right);
ASTNode* createLeaf(char *name);
ASTNode* createLeafInt(int value);
void evaluate(ASTNode* node);
void printAST(ASTNode* node, int level);
void freeAST(ASTNode* node);


#endif

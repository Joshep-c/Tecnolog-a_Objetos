#include "BinaryExpressionTree.h"
// Constructor
BinaryExpressionTree::BinaryExpressionTree(std::unique_ptr<Node> rootNode)
    : root(std::move(rootNode)) {}
// Evaluar el árbol desde la raíz
int BinaryExpressionTree::evaluate()
{
    return root->evaluate();
}

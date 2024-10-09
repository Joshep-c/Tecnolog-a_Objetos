#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H
#include "Node.h"
#include <memory>
class BinaryExpressionTree
{
private:
    std::unique_ptr<Node> root; // Nodo raíz del árbol
public:
    BinaryExpressionTree(std::unique_ptr<Node> rootNode);
    int evaluate(); // Evaluar el árbol completo
};
#endif

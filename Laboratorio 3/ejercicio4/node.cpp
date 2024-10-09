#include "Node.h"
// Implementación de OperandNode
OperandNode::OperandNode(int val) : value(val) {}
int OperandNode::evaluate()
{
    return value;
}
// Implementación de OperatorNode
OperatorNode::OperatorNode(char oper, std::unique_ptr<Node> leftNode,std::unique_ptr<Node> rightNode)
    : op(oper), left(std::move(leftNode)), right(std::move(rightNode)) {}
int OperatorNode::evaluate()
{
    int leftVal = left->evaluate();
    int rightVal = right->evaluate();
    if (op == '+')
    {
        return leftVal + rightVal;
    }
    else if (op == '*')
    {
        return leftVal * rightVal;
    }
    return 0; // Si el operador no es reconocido
}

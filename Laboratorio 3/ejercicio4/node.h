#ifndef NODE_H
#define NODE_H
#include <memory>
class Node
{
public:
    virtual int evaluate() = 0;
    virtual ~Node() = default; // Destructor virtual
};
class OperandNode : public Node
{
private:
    int value; // Valor numérico
public:
    OperandNode(int val);    // Constructor
    int evaluate() override; // Evaluar el valor del operando
};
class OperatorNode : public Node
{
private:
    char op; // Operador ('+' o '*')
    std::unique_ptr<Node> left, right;

public:
    OperatorNode(char oper, std::unique_ptr<Node> leftNode,
                 std::unique_ptr<Node> rightNode);
    int evaluate() override; // Evaluar el resultado de la operación
};
#endif

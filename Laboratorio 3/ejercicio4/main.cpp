#include <iostream>
#include "BinaryExpressionTree.h"
#include "Node.h"
using namespace std;
int main()
{
    // Construir el árbol basado en la expresión: 54 + 5 * 34 + 1 * 2
    auto leftSubTree = make_unique<OperatorNode>('+',
                                                 make_unique<OperandNode>(54),
                                                 make_unique<OperatorNode>('*',
                                                                           make_unique<OperandNode>(5),
                                                                           make_unique<OperandNode>(34)));
    auto rightSubTree = make_unique<OperatorNode>('*',
                                                  make_unique<OperandNode>(1),
                                                  make_unique<OperandNode>(2));
    // Crear el árbol completo
    BinaryExpressionTree tree(make_unique<OperatorNode>('+',std::move(leftSubTree), std::move(rightSubTree)));
    // Evaluar el árbol de expresión
    cout << "Resultado : \n"
         << "54 + 5 * 34 + 1 * 2 = "
         << tree.evaluate() << endl;
    return 0;
}

#ifndef NODO_H
#define NODO_H
#include <memory>
#include <iostream>
class Nodo
{
public:
    int valor;
    std::shared_ptr<Nodo> siguiente;
    std::weak_ptr<Nodo> anterior;
    Nodo(int val) : valor(val), siguiente(nullptr), anterior() {}

    ~Nodo()
    {
        std::cout<<"Destructor de Nodo\n";
    }
};
#endif
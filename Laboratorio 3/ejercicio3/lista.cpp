#include "lista.h"
#include <iostream>
Lista::Lista() : head(nullptr), tail(nullptr)
{
    std::cout << "Constructor por defecto de Lista\n";
}
Lista::~Lista()
{
    std::cout << "Destructor de Lista\n";
}
void Lista::copiaArreglo(int arreglo[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::shared_ptr<Nodo> nuevoNodo =
            std::make_shared<Nodo>(arreglo[i]);
        if (!head)
        {
            head = nuevoNodo;
            tail = nuevoNodo;
        }
        else
        {
            tail->siguiente = nuevoNodo;
            nuevoNodo->anterior = tail;
            tail = nuevoNodo;
        }
    }
}
void Lista::imprimeAdelante() const
{
    std::shared_ptr<Nodo> actual = head;
    std::cout << "Lista (Adelante): ";
    while (actual)
    {
        std::cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    std::cout << "\n";
}
void Lista::imprimeAtras() const
{
    std::shared_ptr<Nodo> actual = tail;
    std::cout << "Lista (Atras): ";
    while (actual)
    {
        std::cout << actual->valor << " ";
        actual = actual->anterior.lock();
    }
    std::cout << "\n";
}
std::shared_ptr<Nodo> Lista::buscarDesdeAdelante(int valor) const
{
    std::shared_ptr<Nodo> actual = head;
    while (actual)
    {
        if (actual->valor == valor)
            return actual;
        actual = actual->siguiente;
    }
    return nullptr; // No encontrado
}
std::shared_ptr<Nodo> Lista::buscarDesdeAtras(int valor) const
{
    std::shared_ptr<Nodo> actual = tail;
    while (actual)
    {
        if (actual->valor == valor)
            return actual;
        actual = actual->anterior.lock();
    }
    return nullptr; // No encontrado
}
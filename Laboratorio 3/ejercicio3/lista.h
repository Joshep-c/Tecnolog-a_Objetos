#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <memory>
class Lista
{
private:
    std::shared_ptr<Nodo> head; // Inicio de la lista
    std::shared_ptr<Nodo> tail; // Final de la lista
public:
    Lista();
    ~Lista();
    // Copia un arreglo de enteros a la lista doblemente enlazada
    void copiaArreglo(int arreglo[], int size);
    // Imprime la lista desde el inicio hacia el final
    void imprimeAdelante() const;
    // Imprime la lista desde el final hacia el inicio
    void imprimeAtras() const;
    // Busca un valor desde el inicio de la lista
    std::shared_ptr<Nodo> buscarDesdeAdelante(int valor) const;
    // Busca un valor desde el final de la lista
    std::shared_ptr<Nodo> buscarDesdeAtras(int valor) const;
};
#endif
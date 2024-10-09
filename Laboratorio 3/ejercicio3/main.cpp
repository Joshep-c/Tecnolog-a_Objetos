#include "lista.h"
#include <iostream>

int main()
{
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int longitud = sizeof(arreglo) / sizeof(*arreglo);
    Lista lista1;
    lista1.copiaArreglo(arreglo, longitud);
    // Imprimir la lista en ambas direcciones
    lista1.imprimeAdelante();
    lista1.imprimeAtras();
    // Buscar un valor desde adelante
    int valorBusqueda = 5;
    std::shared_ptr<Nodo> encontrado = lista1.buscarDesdeAdelante(valorBusqueda);
    if (encontrado)
        std::cout << "Valor " << valorBusqueda << " encontrado desde adelante.\n ";
    else
        std::cout
            << "Valor " << valorBusqueda << " NO encontrado desde adelante.\n ";
    // Buscar un valor desde atrás
    valorBusqueda = 11;
    encontrado = lista1.buscarDesdeAtras(valorBusqueda);
    if (encontrado)
        std::cout << "Valor " << valorBusqueda << " encontrado desde atrás.\n ";
    else
        std::cout
            << "Valor " << valorBusqueda << " NO encontrado desdeatrás.\n ";

    return 0;
}

#include "rectangulo.h"
// Constructor por default
Rectangulo::Rectangulo()
{
    std::cout << "constructor por defecto\n";
    miancho = std::make_unique<USHORT>(10);
    mialto = std::make_unique<USHORT>(2);
    val1 = std::make_unique<int>(0);
    val2 = std::make_unique<int>(0);
    val3 = std::make_unique<int>(0);
}
// Constructor con parametros ancho y alto
Rectangulo::Rectangulo(USHORT ancho, USHORT alto)
{
    std::cout << "constructor normal\n";
    miancho = std::make_unique<USHORT>(ancho);
    mialto = std::make_unique<USHORT>(alto);
    val1 = std::make_unique<int>(0);
    val2 = std::make_unique<int>(0);
    val3 = std::make_unique<int>(0);
}
// Constructor sobrecargado, copia
Rectangulo::Rectangulo(const Rectangulo &R)
{
    std::cout << "constructor copia\n";
    miancho = std::make_unique<USHORT>(*R.miancho);
    mialto = std::make_unique<USHORT>(*R.mialto);
    val1 = std::make_unique<int>(*R.val1);
    val2 = std::make_unique<int>(*R.val2);
    val3 = std::make_unique<int>(*R.val3);
}
// Función para dibujar el rectangulo
void Rectangulo::Dibujar()
{
    *val1 = 1;
    *val2 = 4;
    *val3 = 8;
    Dibujar(*miancho, *mialto);
}
// Sobrecarga de Dibujar
void Rectangulo::Dibujar(USHORT ancho, USHORT alto)
{
    for (USHORT i = 0; i < alto; i++)
    {
        for (USHORT j = 0; j < ancho; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
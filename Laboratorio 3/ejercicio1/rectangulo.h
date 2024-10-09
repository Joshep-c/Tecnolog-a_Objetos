#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <iostream>
#include <memory> // para std::unique_ptr
typedef unsigned short int USHORT;
class Rectangulo
{
private:
    std::unique_ptr<USHORT> miancho;
    std::unique_ptr<USHORT> mialto;
    std::unique_ptr<int> val1, val2, val3;

public:
    Rectangulo(); // Constructor por defecto
    Rectangulo(USHORT ancho, USHORT alto);
    Rectangulo(const Rectangulo &R);
    ~Rectangulo() {} // Destructor
    void Dibujar();
    void Dibujar(USHORT xancho, USHORT xalto);
};
#endif

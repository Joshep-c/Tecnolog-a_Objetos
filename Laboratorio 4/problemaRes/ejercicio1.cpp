#include <iostream>
#include <string>

using namespace std;

class infante
{
private:
    string nombre;

public:
    infante(const string &nom) : nombre(nom) {}

    void gatear()
    {
        cout << nombre << " gateando ... \n";
    }

    string getNombre()
    {
        return nombre;
    }
};

class joven
{
private:
    string nombre;

public:
    joven(const string &nom) : nombre(nom) {}

    void correr()
    {
        cout << nombre << " corriendo ... \n";
    }

    string getNombre()
    {
        return nombre;
    }
};

class adulto : public infante, public joven
{
private:
    string nombre;

public:
    adulto(const string &nom) : infante(nom), joven(nom), nombre(nom) {}

    void caminar()
    {
        cout << nombre << " caminando ... \n";
    }
};

int main()
{
    adulto persona("Juan");

    // Llamando a los métodos de las clases base
    persona.gatear();
    persona.correr();
    persona.caminar();

    return 0;
}

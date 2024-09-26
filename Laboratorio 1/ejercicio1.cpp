#include <iostream>
#include <cmath>

using namespace std;

void verificarCuboPerfecto(int numero) {
    int suma = 0, digito, temp = numero;
    string expresion = "";

    while (temp != 0) {
        digito = temp % 10;                     
        suma += pow(digito, 3);                

        expresion = to_string(digito) + "^3" + (temp >= 10 ? " + " : "") + expresion;

        temp /= 10;                   
    }

    cout << expresion << " = " << suma;

    if (suma == numero) {
        cout << ". -> es cubo perfecto" << endl;
    } else {
        cout << " != " << numero << ". -> no es cubo perfecto" << endl;
    }
}

int main() {
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    verificarCuboPerfecto(numero);

    return 0;
}

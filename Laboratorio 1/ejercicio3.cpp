#include <iostream>
using namespace std;


int encontrarDivisores(int numero, int divisores[]) {
    int contador = 0;

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores[contador] = i;
            contador++;
        }
    }
    return contador;
}

void imprimirDivisores(int divisores[], int cantidad) {
    cout << "Divisores: ";
    for (int i = 0; i < cantidad; i++) {
        cout << divisores[i];
        if (i < cantidad - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    int divisores[numero]; 

    int cantidadDivisores = encontrarDivisores(numero, divisores);

    imprimirDivisores(divisores, cantidadDivisores);

    cout << "Cantidad de divisores: " << cantidadDivisores << endl;

    return 0;
}

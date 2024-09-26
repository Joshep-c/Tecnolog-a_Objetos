#include <iostream>
#include <cstdlib>
#include <ctime>   
using namespace std;

struct Persona {
    int edad;
    int gradoInstruccion;
};

int generarEdad() {
    return rand() % 66 + 15;
}

int generarGradoInstruccion() {
    return rand() % 3 + 1; 
}

float calcularPromedioEdades(Persona personas[], int N) {
    int sumaEdades = 0;
    for (int i = 0; i < N; i++) {
        sumaEdades += personas[i].edad;
    }
    return static_cast<float>(sumaEdades) / N;
}

int encontrarMayorEdad(Persona personas[], int N) {
    int mayorEdad = personas[0].edad;
    for (int i = 1; i < N; i++) {
        if (personas[i].edad > mayorEdad) {
            mayorEdad = personas[i].edad;
        }
    }
    return mayorEdad;
}

void contarGrados(Persona personas[], int N, int &primaria, int &secundaria, int &superior) {
    primaria = secundaria = superior = 0;
    for (int i = 0; i < N; i++) {
        switch (personas[i].gradoInstruccion) {
            case 1:
                primaria++;
                break;
            case 2:
                secundaria++;
                break;
            case 3:
                superior++;
                break;
        }
    }
}

int main() {
    int N;

    cout << "Ingrese el numero de personas para la encuesta: ";
    cin >> N;

    Persona personas[N];

    srand(time(0));

    // Generar datos
    for (int i = 0; i < N; i++) {
        personas[i].edad = generarEdad();
        personas[i].gradoInstruccion = generarGradoInstruccion();
    }

    float promedioEdades = calcularPromedioEdades(personas, N);

    int mayorEdad = encontrarMayorEdad(personas, N);
    
    int primaria, secundaria, superior;
    contarGrados(personas, N, primaria, secundaria, superior);

    // Resultados
    cout << "Resultados de la encuesta:" << endl;
    cout << "a) Promedio de edades: " << promedioEdades << endl;
    cout << "b) Mayor edad: " << mayorEdad << endl;
    cout << "c) Cantidad de personas con instruccion Primaria: " << primaria << endl;
    cout << "d) Cantidad de personas con instruccion Secundaria: " << secundaria << endl;
    cout << "e) Cantidad de personas con instruccion Superior: " << superior << endl;

    return 0;
}

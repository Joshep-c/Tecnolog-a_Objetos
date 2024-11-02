#include <iostream>

// Declaración del template
template <typename mitipo>
mitipo aritmetica(mitipo x, mitipo y) {
    return x + y;
}

int main() {
    // Llamadas al template con diferentes tipos de datos
    int resultadoInt = aritmetica<int>(10, 45);
    float resultadoFloat = aritmetica<float>(0.14f, 0.147f);
    double resultadoDouble = aritmetica<double>(3.5, 8.10);

    // Mostrar los resultados
    std::cout << "Resultado int: " << resultadoInt << std::endl;
    std::cout << "Resultado float: " << resultadoFloat << std::endl;
    std::cout << "Resultado double: " << resultadoDouble << std::endl;

    return 0;
}

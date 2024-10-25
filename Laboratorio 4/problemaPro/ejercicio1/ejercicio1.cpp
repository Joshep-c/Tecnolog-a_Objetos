#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main()
{

    std::srand(std::time(0)); // Inicializar la semilla de números aleatorios
    std::vector<int> numbers(30); // Crear un vector de 30 elementos

    // Rellenar el vector con números aleatorios entre 1 y 100
    std::generate(numbers.begin(), numbers.end(), []() { return std::rand() % 100 + 1; });

    // Contar los números impares menores de 20
    int count = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n < 20 && n % 2 != 0;
    });

    std::cout << "Números impares menores de 20: " << count << std::endl;

    return 0;
}

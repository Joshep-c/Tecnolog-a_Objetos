#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main()
{

    std::srand(std::time(0));
    std::vector<int> numbers(30);

    std::vector<int> resultados;
    
    std::cout << std::endl;
    // Rellenar el vector inicial "numbers"
    std::generate(numbers.begin(), numbers.end(), []() { return std::rand() % 100 + 1; });

    // Contar los números impares menores de 20 y agregarlos al vector "resultados"
    int count = std::count_if(numbers.begin(), numbers.end(), [&resultados](int n) {
        if (n < 20 && n % 2 != 0) {
            resultados.push_back(n); 
            return true;
        }
        return false;
    });

    std::cout << "Numeros impares menores de 20: " << count << std::endl;

    for (int n : resultados) {
        std::cout << n << " ";
    }

    return 0;
}

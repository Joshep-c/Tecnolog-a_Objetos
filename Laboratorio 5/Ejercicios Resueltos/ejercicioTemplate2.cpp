#include <iostream>

char mayorLetras(char a, char b){
    return (a > b ? a : b);
}

int mayorNumeros(int a, int b){
    return (a >b ? a : b);
}

template <typename Tipo> Tipo mayorDe(Tipo a, Tipo b){
    return (a > b ? a : b);
}

int main(){
    char x = mayorDe<char>('e', 'z');
    int y = mayorDe<int>(9, 4);

    std::cout << "El caracter mayor es: " << x << std::endl;
    std::cout << "El numero mayor es: " << y << std::endl;

    return 0;
}
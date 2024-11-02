#include <iostream>

template <typename T>
class Contenedor {
public:
    T metodo1 (int xx){
        return array[xx];
    }
    void metodo2 (T val, int i){
        array[i] = val;
    }
    void mostrar() const;
private:
    T array[4];
};

// Declaración del template
template <typename T>
void Contenedor<T>:: mostrar() const {
    for (int i=0; i <= 4; i++){
        std::cout << array[i] << std::endl;
    }
}

int main() {
    

    Contenedor<int> z;
    z.metodo2(10, 0);
    z.metodo2(50, 1);
    z.metodo2(60, 2);
    z.metodo2(70, 3);

    z.mostrar();

    return 0;
}

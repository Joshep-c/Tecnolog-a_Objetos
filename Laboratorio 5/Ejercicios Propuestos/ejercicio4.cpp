#include <iostream>
#include <vector>

template <class T>
class Pila {
private:
    std::vector<T> elementos;
    
public:
    // Método para insertar un elemento
    void push(T elemento) {
        elementos.push_back(elemento);
        std::cout << "Elemento " << elemento << " insertado en la pila." << std::endl;
    }

    // Método para remover el elemento superior
    void pop() {
        if (!elementos.empty()) {
            T elemento = elementos.back();
            elementos.pop_back();
            std::cout << "Elemento " << elemento << " removido de la pila." << std::endl;
        } else {
            std::cout << "La pila está vacía. No se puede hacer pop." << std::endl;
        }
    }

    // Método para ver el elemento en la parte superior
    T top() const {
        if (!elementos.empty()) {
            return elementos.back();
        } else {
            throw std::out_of_range("La pila está vacía.");
        }
    }

    // Verifica si la pila esta vacia
    bool isEmpty() const {
        return elementos.empty();
    }

    // Retorna el tamaño de la pila
    int size() const {
        return elementos.size();
    }
};

int main() {
    // Pila de enteros
    Pila<int> pilaEnteros;
    pilaEnteros.push(10);
    pilaEnteros.push(20);
    pilaEnteros.push(30);
    std::cout << "Elemento entero superior de la pila: " << pilaEnteros.top() << std::endl;
    pilaEnteros.pop();
    std::cout << "Cantidad de elementos de la pila despues de pop(): " << pilaEnteros.size() << std::endl;

    // Pila de caraceteres
    Pila<char> pilaCaracteres;
    pilaCaracteres.push('A');
    pilaCaracteres.push('B');
    pilaCaracteres.push('C');
    std::cout << "Elemento char superior de la pila: " << pilaCaracteres.top() << std::endl;
    pilaCaracteres.pop();
    std::cout << "Cantidad de elementos de la pila despues de pop(): " << pilaCaracteres.size() << std::endl;

    return 0;
}

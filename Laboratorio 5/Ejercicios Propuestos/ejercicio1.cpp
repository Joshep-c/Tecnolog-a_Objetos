#include <iostream>
#include <string>

// Nodo de la lista enlazada
template <typename T>
class Node {
public:
    T data;               
    Node<T>* next;    

    Node(T value) : data(value), next(nullptr) {}
};

// Clase LinkedList - lista enlazada
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:

    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Agregar un elemento al final de la lista
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Imprimir los elementos de la lista
    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Lista de enteros (secuencia de edades)
    LinkedList<int> ageList;
    ageList.append(25);
    ageList.append(30);
    ageList.append(35);
    std::cout << "Secuencia de edades: ";
    ageList.print();

    // Lista de cadenas (secuencia de palabras)
    LinkedList<std::string> wordList;
    wordList.append("Hola");
    wordList.append("mundo");
    wordList.append("template");
    std::cout << "Secuencia de palabras: ";
    wordList.print();

    return 0;
}

#include <QCoreApplication>
#include <QDebug>
#include <thread>
#include <mutex>
#include <random>
#include <memory>

// Nodo de la lista enlazada
struct Node {
    int value;
    std::shared_ptr<Node> next;
    Node(int val) : value(val), next(nullptr) {}
};

// Clase de la lista enlazada simple
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // Inserta un valor al inicio de la lista
    void insert(int val) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto newNode = std::make_shared<Node>(val);
        newNode->next = head;
        head = newNode;
        qDebug() << "Insertando:" << val;
    }

    // Elimina el primer nodo que contiene el valor especificado
    bool remove(int val) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto current = head;
        std::shared_ptr<Node> prev = nullptr;

        while (current != nullptr) {
            if (current->value == val) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                qDebug() << "Eliminando:" << val;
                return true;
            }
            prev = current;
            current = current->next;
        }
        qDebug() << "No se eliminó:" << val;
        return false;
    }

    // Busca un valor en la lista
    bool search(int val) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto current = head;

        while (current != nullptr) {
            if (current->value == val) {
                qDebug() << "Buscado:" << val << "- Encontrado";
                return true;
            }
            current = current->next;
        }
        qDebug() << "Buscado:" << val << "- No encontrado";
        return false;
    }

    // Modifica un valor sumándole una cantidad
    bool modify(int val, int increment) {
        std::lock_guard<std::mutex> lock(listMutex);
        auto current = head;

        while (current != nullptr) {
            if (current->value == val) {
                int oldVal = current->value;
                current->value += increment;
                qDebug() << "Modificando" << oldVal << "a" << current->value;
                return true;
            }
            current = current->next;
        }
        qDebug() << "No se encontró:" << val;
        return false;
    }

private:
    std::shared_ptr<Node> head;
    std::mutex listMutex;
};

// Genera un número aleatorio
int getRandomNumber(int min, int max) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

// Función del hilo para insertar elementos
void threadInsert(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int val = getRandomNumber(1, 100);
        list.insert(val);
    }
}

// Función del hilo para eliminar elementos
void threadRemove(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int val = getRandomNumber(1, 100);
        list.remove(val);
    }
}

// Función del hilo para buscar elementos
void threadSearch(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int val = getRandomNumber(1, 100);
        list.search(val);
    }
}

// Función del hilo para modificar elementos
void threadModify(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int val = getRandomNumber(1, 100);
        int increment = getRandomNumber(1, 10);
        list.modify(val, increment);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinkedList list;

    // Crear hilos
    std::thread t1(threadRemove, std::ref(list));
    std::thread t2(threadInsert, std::ref(list));
    std::thread t3(threadSearch, std::ref(list));
    std::thread t4(threadModify, std::ref(list));

    // Esperar a que los hilos terminen
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return a.exec();
}

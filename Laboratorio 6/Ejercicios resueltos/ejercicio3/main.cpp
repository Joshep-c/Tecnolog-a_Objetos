#include <QCoreApplication>
#include <QDebug>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
#include <vector>

// Mutex para proteger el acceso al vector de primos
std::mutex vectLock;
std::vector<unsigned int> primeVect;

// Función para encontrar números primos sin hilos
void FindPrimes1(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
    for (unsigned int x = start; x <= end; x += 2) {
        bool isPrime = true;
        for (unsigned int y = 2; y * y <= x; y++) {
            if (x % y == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            vect.push_back(x);
        }
    }
}

// Función para encontrar números primos con protección de mutex
void FindPrimes(unsigned int start, unsigned int end) {
    for (unsigned int x = start; x <= end; x += 2) {
        bool isPrime = true;
        for (unsigned int y = 2; y * y <= x; y++) {
            if (x % y == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::lock_guard<std::mutex> lock(vectLock);
            primeVect.push_back(x);
        }
    }
}

// Función para gestionar los hilos y dividir la carga de trabajo
void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads) {
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = (end - start + 1) / numThreads;

    unsigned int newStart = start;
    unsigned int newEnd = start + threadSpread;

    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(FindPrimes, newStart, newEnd);
        newStart = newEnd + 1;
        newEnd += threadSpread;
        if (x == numThreads - 2) {
            newEnd = end;
        }
    }

    for (auto& t : threadVect) {
        t.join();
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // SIN HILOS
    std::vector<unsigned int> primeVectWithoutThreads;
    int startTime = clock();

    // Encontrar primos sin hilos
    FindPrimes1(1, 1000000, primeVectWithoutThreads);

    // Tiempo final y tiempo de ejecución sin hilos
    int endTime = clock();
    qDebug() << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC);

    // CON HILOS
    startTime = clock();
    FindPrimesWithThreads(1, 1000000, 8);

    // Tiempo final y tiempo de ejecución con hilos
    endTime = clock();
    qDebug() << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC);

    return a.exec();
}

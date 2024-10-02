#include <iostream>
#include <string>

using namespace std;

// Estructura para representar una pagina web en el historial
struct WebPage {
    string url;
    WebPage* next;
    WebPage* prev;

    WebPage(const string& u) : url(u), next(nullptr), prev(nullptr) {}
};

// Clase que maneja el historial de navegacion
class BrowserHistory {
private:
    WebPage* current;

public:
    BrowserHistory() : current(nullptr) {}

    // Visitar una nueva pagina
    void visit(const string& url) {
        WebPage* newPage = new WebPage(url);
        if (!current) {
            current = newPage;
        } else {
            current->next = newPage;
            newPage->prev = current;
            current = newPage;
        }
        cout << "Visitando: " << url << endl;
    }

    // Retroceder en el historial
    void back() {
        if (current && current->prev) {
            current = current->prev;
            cout << "Retrocediendo a: " << current->url << endl;
        } else {
            cout << "No se puede retroceder mas." << endl;
        }
    }

    // Avanzar en el historial
    void forward() {
        if (current && current->next) {
            current = current->next;
            cout << "Avanzando a: " << current->url << endl;
        } else {
            cout << "No se puede avanzar mas." << endl;
        }
    }

    // Mostrar la pagina actual
    void showCurrent() {
        if (current) {
            cout << "Pagina actual: " << current->url << endl;
        } else {
            cout << "No hay paginas en el historial." << endl;
        }
    }
};

// Funcion main para probar el historial de navegacion
int main() {
    BrowserHistory history;

    history.visit("google.com");
    history.visit("stackoverflow.com");
    history.visit("github.com");

    history.showCurrent();  // Mostrar pagina actual

    history.back();  // Retroceder una pagina
    history.back();  // Retroceder otra pagina

    history.forward();  // Avanzar una pagina

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    // Lambda que suma un número y lo muestra
    auto s = [](int valor) { return valor + 3; };
    int u = 5;
    cout << s(u) << endl;  // Muestra el resultado de sumar 3 a 'u'

    // Lambda para recorrer elementos de un vector
    vector<int> v = {5, 2, 3, 7, 1, 0, 14, 20};
    
    for_each(v.begin(), v.end(), [](int valor) {
        cout << valor << endl;  // Muestra cada elemento del vector
    });

    return 0;
}

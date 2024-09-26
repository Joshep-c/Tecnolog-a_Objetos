#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase Producto
class Producto {
public:
    string nombre;
    double precio;
    int cantidad;

    Producto(string nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}
};

// Clase Billetera
class Billetera {
private:
    double saldo;
    vector<Producto> productosEnCarrito;
    int cantidadProductosComprados;

public:
    // Constructor
    Billetera(double saldoInicial) : saldo(saldoInicial), cantidadProductosComprados(0) {}

    // Métodos
    void agregarAlCarrito(Producto producto) {
        productosEnCarrito.push_back(producto);
        cout << producto.nombre << " agregado al carrito." << endl;
    }

    void eliminarDelCarrito(string nombreProducto) {
        for (auto it = productosEnCarrito.begin(); it != productosEnCarrito.end(); ++it) {
            if (it->nombre == nombreProducto) {
                productosEnCarrito.erase(it);
                cout << nombreProducto << " eliminado del carrito." << endl;
                return;
            }
        }
        cout << nombreProducto << " no encontrado en el carrito." << endl;
    }

    void finalizarCompra() {
        double total = calcularTotal();
        if (saldo >= total) {
            saldo -= total;
            cantidadProductosComprados += productosEnCarrito.size();
            productosEnCarrito.clear();
            cout << "Compra finalizada. Total: " << total << ". Saldo restante: " << saldo << endl;
        } else {
            cout << "Saldo insuficiente para completar la compra." << endl;
        }
    }

    double consultarSaldo() const {
        return saldo;
    }

    void verCarrito() const {
        cout << "Productos en el carrito: " << endl;
        for (const auto& producto : productosEnCarrito) {
            cout << "- " << producto.nombre << " (Cantidad: " << producto.cantidad << ", Precio: " << producto.precio << ")" << endl;
        }
    }

    double calcularTotal() const {
        double total = 0;
        for (const auto& producto : productosEnCarrito) {
            total += producto.precio * producto.cantidad;
        }
        return total;
    }
};

int main() {
    Billetera miBilletera(100.0);

    // Crear productos
    Producto producto1("Laptop", 50.0, 1);
    Producto producto2("Mouse", 10.0, 2);
    
    // Agregar productos
    miBilletera.agregarAlCarrito(producto1);
    miBilletera.agregarAlCarrito(producto2);

    // Ver carrito
    miBilletera.verCarrito();

    // Consultar saldo
    cout << "Saldo actual: " << miBilletera.consultarSaldo() << endl;

    // Finalizar compra
    miBilletera.finalizarCompra();

    // Saldo después de la compra
    cout << "Saldo despuEs de la compra: " << miBilletera.consultarSaldo() << endl;

    return 0;
}

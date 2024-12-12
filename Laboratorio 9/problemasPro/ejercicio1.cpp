#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <ctime>
#include <mutex>

// Enumeracion para los tipos de cuenta
enum class TipoCuenta
{
    AHORRO,
    JOVEN,
    PLUSS,
    EMPRESARIAL,
    TARJETA_CREDITO
};

// Clase base para cuentas
class Cuenta
{
protected:
    TipoCuenta tipo;
    float tasaInteres;

public:
    Cuenta(TipoCuenta tipo, float tasa) : tipo(tipo), tasaInteres(tasa) {}
    virtual ~Cuenta() = default;

    virtual void mostrarDetalles() const
    {
        std::cout << "Tipo de cuenta: " << static_cast<int>(tipo)
                  << ", Tasa de interes: " << tasaInteres << "%" << std::endl;
    }
    float getTasaInteres() const { return tasaInteres; }
    TipoCuenta getTipo() const { return tipo; }
};

// Clases derivadas (ejemplo: Cuenta Ahorro)
class CuentaAhorro : public Cuenta
{
public:
    CuentaAhorro() : Cuenta(TipoCuenta::AHORRO, 0.5f) {}
};

// Clase Cliente
class Cliente
{
private:
    std::string nombre;
    std::vector<std::shared_ptr<Cuenta>> cuentas;

public:
    Cliente(const std::string &nombre) : nombre(nombre) {}
    void agregarCuenta(std::shared_ptr<Cuenta> cuenta)
    {
        cuentas.push_back(cuenta);
    }
    void generarEstadoCuenta(time_t fechaCorte) const
    {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Estado de cuenta para: " << nombre << std::endl;
        std::cout << "Fecha de corte: " << std::ctime(&fechaCorte);
        for (const auto &cuenta : cuentas)
        {
            cuenta->mostrarDetalles();
        }
    }
};

// Singleton para el repositorio de cuentas
class RepositorioCuentas
{
private:
    std::unordered_map<std::string, std::shared_ptr<Cliente>> clientes;
    static std::shared_ptr<RepositorioCuentas> instancia;
    static std::mutex mtx;

    RepositorioCuentas() = default;

public:
    static std::shared_ptr<RepositorioCuentas> obtenerInstancia()
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instancia)
        {
            instancia = std::shared_ptr<RepositorioCuentas>(new RepositorioCuentas());
        }
        return instancia;
    }

    void registrarCliente(const std::string &nombre)
    {
        if (clientes.find(nombre) == clientes.end())
        {
            clientes[nombre] = std::make_shared<Cliente>(nombre);
        }
    }

    void agregarCuenta(const std::string &nombre, std::shared_ptr<Cuenta> cuenta)
    {
        if (clientes.find(nombre) != clientes.end())
        {
            clientes[nombre]->agregarCuenta(cuenta);
        }
        else
        {
            std::cerr << "Cliente no registrado: " << nombre << std::endl;
        }
    }

    void generarEstadoCuenta(const std::string &nombre, time_t fechaCorte)
    {
        if (clientes.find(nombre) != clientes.end())
        {
            clientes[nombre]->generarEstadoCuenta(fechaCorte);
        }
        else
        {
            std::cerr << "Cliente no encontrado: " << nombre << std::endl;
        }
    }
};

std::shared_ptr<RepositorioCuentas> RepositorioCuentas::instancia = nullptr;
std::mutex RepositorioCuentas::mtx;

// Ejemplo de uso
int main()
{
    auto repositorio = RepositorioCuentas::obtenerInstancia();

    repositorio->registrarCliente("Juan Perez");
    repositorio->registrarCliente("Maria Garcia");

    repositorio->agregarCuenta("Juan Perez", std::make_shared<CuentaAhorro>());
    repositorio->agregarCuenta("Maria Garcia", std::make_shared<CuentaAhorro>());

    time_t fechaCorte = time(nullptr);
    repositorio->generarEstadoCuenta("Juan Perez", fechaCorte);
    repositorio->generarEstadoCuenta("Maria Garcia", fechaCorte);

    return 0;
}

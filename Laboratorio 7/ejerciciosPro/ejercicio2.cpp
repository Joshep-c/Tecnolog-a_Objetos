#include <iostream>
#include <vector>
#include <map>
#include <functional>

class Cuenta
{
protected:
    std::string tipo;
    double saldo;
    double interes;
    std::string moneda;

public:
    Cuenta(std::string t, double s, double i, std::string m)
        : tipo(t), saldo(s), interes(i), moneda(m) {}
    virtual ~Cuenta() {}

    virtual void CalcularInteres()
    {
        saldo += saldo * interes;
    }

    virtual void MostrarEstado()
    {
        std::cout << "Cuenta: " << tipo << " | Saldo: " << saldo << " " << moneda << " | Interes: " << interes * 100 << "%" << std::endl;
    }
};

class Ahorro : public Cuenta
{
public:
    Ahorro(double s, std::string m) : Cuenta("Ahorro", s, 0.0045, m) {}
};

class Joven : public Cuenta
{
public:
    Joven(double s, std::string m) : Cuenta("Joven", s, 0.015, m) {}
};

class Empresarial : public Cuenta
{
public:
    Empresarial(double s, std::string m) : Cuenta("Empresarial", s, 0.025, m) {}
};

// Operaciones de transferencia usando lambdas
auto transferencia = [](double monto, double tasa)
{
    return monto * (1 - tasa);
};

// Ejemplo en el main
int main()
{
    std::vector<Cuenta*> cuentas;
    cuentas.push_back(new Ahorro(1000, "Soles"));
    cuentas.push_back(new Joven(2000, "Soles"));
    cuentas.push_back(new Empresarial(5000, "Soles"));

    for (Cuenta *c : cuentas)
    {
        c->CalcularInteres();
        c->MostrarEstado();
    }

    double montoTransferencia = 500;
    std::cout << "Transferencia nacional (Soles): " << transferencia(montoTransferencia, 0.005) << " Soles" << std::endl;

    for (Cuenta *c : cuentas)
        delete c;

    return 0;
}

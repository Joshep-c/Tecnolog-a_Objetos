#include <iostream>
#include <vector>
#include <string>

// Producto final: Carro
class Carro
{
    std::vector<std::string> partes; // Almacena las partes del automóvil

public:
    void AgregarParte(const std::string &parte)
    {
        partes.push_back(parte);
    }

    void Mostrar() const
    {
        std::cout << "Detalles del automovil:\n";
        for (const auto &parte : partes)
        {
            std::cout << "- " << parte << std::endl;
        }
    }
};

// Interfaz IBuilder
class IBuilder
{
public:
    virtual ~IBuilder() {}
    virtual void ConstruirMotor(const std::string &color) = 0;
    virtual void ConstruirPuertas(const std::string &color) = 0;
    virtual void ConstruirLlantas(const std::string &color) = 0;
    virtual void ConstruirAsientos(const std::string &material) = 0;
    virtual Carro *ObtenerResultado() = 0;
};

// Builder Específico: CarBuilder
class CarBuilder : public IBuilder
{
    Carro *carro;

public:
    CarBuilder() { carro = new Carro(); }

    void ConstruirMotor(const std::string &color) override
    {
        carro->AgregarParte("Motor color " + color);
    }

    void ConstruirPuertas(const std::string &color) override
    {
        carro->AgregarParte("Puertas color " + color);
    }

    void ConstruirLlantas(const std::string &color) override
    {
        carro->AgregarParte("Llantas color " + color);
    }

    void ConstruirAsientos(const std::string &material) override
    {
        carro->AgregarParte("Asientos de " + material);
    }

    Carro *ObtenerResultado() override
    {
        Carro *resultado = carro;
        carro = new Carro(); // Reseteamos el builder
        return resultado;
    }
};

// Director
class Director
{
    IBuilder *builder;

public:
    void SetBuilder(IBuilder *nuevoBuilder)
    {
        builder = nuevoBuilder;
    }

    void ConstruirCarroDeportivo()
    {
        builder->ConstruirMotor("Rojo");
        builder->ConstruirPuertas("Negro");
        builder->ConstruirLlantas("Negro Mate");
        builder->ConstruirAsientos("Cuero");
    }

    void ConstruirCarroFamiliar()
    {
        builder->ConstruirMotor("Azul");
        builder->ConstruirPuertas("Blanco");
        builder->ConstruirLlantas("Gris");
        builder->ConstruirAsientos("Tela");
    }
};

// Main
int main()
{
    Director director;
    CarBuilder builder;

    // Configuramos el builder en el director
    director.SetBuilder(&builder);

    // Construcción de un carro deportivo
    director.ConstruirCarroDeportivo();
    Carro *deportivo = builder.ObtenerResultado();
    std::cout << "Carro Deportivo:\n";
    deportivo->Mostrar();
    delete deportivo;

    // Construcción de un carro familiar
    director.ConstruirCarroFamiliar();
    Carro *familiar = builder.ObtenerResultado();
    std::cout << "\nCarro Familiar:\n";
    familiar->Mostrar();
    delete familiar;

    return 0;
}

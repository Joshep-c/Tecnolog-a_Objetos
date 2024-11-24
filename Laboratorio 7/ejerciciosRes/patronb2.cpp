#include <iostream>
#include <vector>
#include <string>

class IBuilder {
public:
    virtual ~IBuilder() {}
    virtual void ProducirParteA() = 0;
    virtual void ProducirParteB() = 0;
    virtual void ProducirParteC() = 0;
};

class Product1 {
public:
    std::vector<std::string> componentes;

    void ListaComp() const {
        std::cout << "Componentes: ";
        for (size_t i = 0; i < componentes.size(); i++) {
            if (i == componentes.size() - 1) { // Último componente
                std::cout << componentes[i];
            } else {
                std::cout << componentes[i] << ", ";
            }
        }
        std::cout << std::endl;
    }
};

class BuilderEspecifico : public IBuilder {
private:
    Product1 *producto;
public:
    BuilderEspecifico() {
        this->Reset();
    }
    ~BuilderEspecifico() {
        delete producto;
    }
    void Reset() {
        this->producto = new Product1();
    }
    void ProducirParteA() override {
        this->producto->componentes.push_back("ParteA1");
    }
    void ProducirParteB() override {
        this->producto->componentes.push_back("ParteB1");
    }
    void ProducirParteC() override {
        this->producto->componentes.push_back("ParteC1");
    }
    Product1 *GetProduct() {
        Product1 *resultado = this->producto;
        this->Reset();
        return resultado;
    }
};

class Director {
private:
    IBuilder *builder;
public:
    void setBuilder(IBuilder *builder) {
        this->builder = builder;
    }
    void BuildProductoMin() {
        if (builder)
            this->builder->ProducirParteA();
    }
    void BuildProductoCompleto() {
        if (builder) {
            this->builder->ProducirParteA();
            this->builder->ProducirParteB();
            this->builder->ProducirParteC();
        }
    }
};

void ClienteCode(Director &director) {
    BuilderEspecifico *builder = new BuilderEspecifico();
    director.setBuilder(builder);

    std::cout << "Producto básico:\n";
    director.BuildProductoMin();

    Product1 *p = builder->GetProduct();
    p->ListaComp();
    delete p;

    std::cout << "\nProducto completo:\n";
    director.BuildProductoCompleto();

    p = builder->GetProduct();
    p->ListaComp();
    delete p;

    std::cout << "\nProducto personalizado:\n";
    builder->ProducirParteA();
    builder->ProducirParteC();

    p = builder->GetProduct();
    p->ListaComp();
    delete p;

    delete builder;
}

int main() {
    Director *director = new Director();
    ClienteCode(*director);
    delete director;
    return 0;
}

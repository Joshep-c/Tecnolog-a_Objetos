#include <iostream>
#include <vector>

class AbstractFactory{
    public:
        virtual AbstractProductA* createProductA() = 0;
        virtual AbstractProductB* createProductB() = 0;
};

class AbstractProductA{
    public:
        virtual AbstractProductA() {};
        virtual std::string Funcion1_A() = 0;
};

class CProductoA1 : public AbstractProductA{
    public:
        std::string Funcion1_A() const override{
            return "Producto A1";
        }
};

class CProductoA2 : public AbstractProductA{
    public:
        std::string Funcion1_A() const override{
            return "Producto A2";
        }
};

class AbstractProductB{
    public:
        virtual AbstractProductB() {};
        virtual std::string Funcion1_B() const = 0;
        virtual std::string Funcion2_B (const AbstractProductA& colaborador) const = 0;
};

class CProductoB1 : public AbstractProductB{
    public:
        std::string Funcion1_B() const override{
            return "Producto B1";
        }
        std::string Funcion2_B(const AbstractProductA& colaborador) const override{
            const std::string result = colaborador.Funcion1_A();
            return "B1 con ayuda de " + result;
        }
};

class CProductoB2 : public AbstractProductB{
    public:
        std::string Funcion1_B() const override{
            return "Producto B2";
        }
        std::string Funcion2_B(const AbstractProductA& colaborador) const override{
            const std::string result = colaborador.Funcion1_A();
            return "B2 con ayuda de " + result;
        }
};

class CFactory1 : public AbstractFactory{
    public:
        AbstractProductA* createProductA() override{
            return new CProductoA1();
        }
        AbstractProductB* createProductB() override{
            return new CProductoB1();
        }
};

class CFactory2 : public AbstractFactory{
    public:
        AbstractProductA* createProductA() override{
            return new CProductoA2();
        }
        AbstractProductB* createProductB() override{
            return new CProductoB2();
        }
};

void Cliente(const AbstractFactory& f){
    const AbstractProductA* producto_a = f.createProductA();
    const AbstractProductB* producto_b = f.createProductB();
    std::cout << producto_b->Funcion1_B() << std::endl;
    std::cout << producto_b->Funcion2_B(*producto_a) << std::endl;
    delete producto_a;
    delete producto_b;
}

int main(){
    std::cout << "Cliente: Tipo 1:" << std::endl;
    CFactory1* factory1 = new CFactory1();
    Cliente(*factory1);
    delete factory1;
    std::cout << std::endl;
    std::cout << "Cliente: Tipo 2:" << std::endl;
    CFactory2* factory2 = new CFactory2();
    Cliente(*factory2);
    delete factory2;
    return 0;
}
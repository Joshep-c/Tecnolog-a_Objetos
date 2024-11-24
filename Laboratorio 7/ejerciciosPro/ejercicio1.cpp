#include <iostream>
#include <vector>
using namespace std;

class item
{
public:
    virtual string GetName() { return ""; };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};
class Processor : public item
{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};
class IntelI5 : public Processor
{
    string GetName()
    {
        return "Intel i5";
    }
    float GetPrice()
    {
        return 3000.00;
    }
    void GetConfiguration()
    {
        cout << "1.50 Ghz, up to 2.0 Ghz with turbo, 2 cores, 4 threads, 8 MB cache, RAM 4 GB - 8 GB" << endl;
    }
};
class IntelI7 : public Processor
{
    string GetName()
    {
        return "Intel i7";
    }
    float GetPrice()
    {
        return 4700.00;
    }
    void GetConfiguration()
    {
        cout << "1.6 Ghz, up to 1.99 Ghz, 9na Gen, 4 cores, 8 threads, 16 MB cache, RAM 16 GB" << endl;
    }
};

class Drive : public item{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class HDD : public Drive{
    string GetName(){
        return "Hard disk drive: ";
    }
    float GetPrice(){
        return 150.00;
    }
    void GetConfiguration(){
        cout << "capacity: 1TB, data transfer 1050 mbits/s" << endl;
    }
};

class SDD : public Drive{
    string GetName(){
        return "Solid state drive: ";
    }
    float GetPrice(){
        return 270.00;
    }
    void GetConfiguration(){
        cout << "capacity: 250 GB, data transfer 1800 mbits/s" << endl;
    }
};

class DisplayType : public item{
    virtual string GetName() { return string(""); };
    virtual float GetPrice() { return 0.0; };
    virtual void GetConfiguration() {};
};

class Normal : public DisplayType {
    string GetName(){
        return "Non-touch screen: ";
    }
    float GetPrice(){
        return 195.00;
    }
    void GetConfiguration(){
        cout << "15.6 inch FHD(1920 x 1080), plane, ..., etc." << endl;
    }
};

class Laptop{
public: 
    void AddParts(item *item){
        mLaptopParts.push_back(item);
    }
    float GetCost(){
        float cost = 0.0;
        for (auto item : mLaptopParts){
            cost += item->GetPrice();
        }
        return cost;
    }

    void GetConfiguration(){
        for (auto i=0; i<mLaptopParts.size(); i++){
            cout << mLaptopParts[i]->GetName() << " : ";
            mLaptopParts[i]->GetConfiguration();
        }
    }
private:
    vector <item*> mLaptopParts;
};
class Color : public item {
    string GetName() override { return "Color"; }
    float GetPrice() override { return 50.00; }
    void GetConfiguration() override {
        cout << "Disponible en negro, plateado, azul y blanco." << endl;
    }
};

class Marca : public item {
    string GetName() override { return "Marca"; }
    float GetPrice() override { return 0.0; }
    void GetConfiguration() override {
        cout << "Marcas disponibles: Lenovo, HP, Dell, Asus." << endl;
    }
};

class MonitorPlasma : public item {
    string GetName() override { return "Monitor Plasma"; }
    float GetPrice() override { return 300.00; }
    void GetConfiguration() override {
        cout << "Monitor Plasma 15.6 pulgadas FHD con HDR." << endl;
    }
};

class Impresora : public item {
    string GetName() override { return "Impresora"; }
    float GetPrice() override { return 200.00; }
    void GetConfiguration() override {
        cout << "Impresora multifuncion laser en color." << endl;
    }
};

// Actualización en LaptopBuilder
class LaptopBuilder {
public:
    Laptop *opcionAvanzada() {
        Laptop *lap = new Laptop();
        lap->AddParts(new IntelI7());
        lap->AddParts(new Normal());
        lap->AddParts(new SDD());
        lap->AddParts(new Color());
        lap->AddParts(new MonitorPlasma());
        lap->AddParts(new Impresora());
        return lap;
    }
};

// Uso en el main
int main() {
    LaptopBuilder builder;
    cout << "Laptop Avanzada:\n";
    Laptop *avanzada = builder.opcionAvanzada();
    avanzada->GetConfiguration();
    cout << "Precio total: " << avanzada->GetCost() << endl;
    delete avanzada;
    return 0;
}

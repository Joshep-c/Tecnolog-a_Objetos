#include <iostream>

using namespace std;

class Mamifero
{
public:
    Mamifero() : edad(0) 
    {
        cout << "Mamifero constructor ... \n";
    }

    virtual ~Mamifero() 
    {
        cout << "Mamifero destructor ... \n";
    }

    virtual void Move() const
    {
        cout << "Mamifero move one step\n";
    }

    virtual void Speak() const 
    {
        cout << "Mamifero speak! \n";
    }

protected:
    int edad;
};

class Dog : public Mamifero
{
public:
    Dog() 
    {
        cout << "Dog Constructor ... \n";
    }

    ~Dog() 
    {
        cout << "Dog destructor ... \n";
    }

    void WagTail() 
    {
        cout << "Wagging Tail ... \n";
    }

    void Speak() const override
    {
        cout << "Woof!\n";
    }

    void Move() const override
    {
        cout << "Dog moves 5 steps... \n";
    }
};

int main()
{
    Mamifero *mamiferoPtr = new Dog();  // Uso de polimorfismo
    mamiferoPtr->Move();                // Se llama a la versión de 'Move' en la clase derivada
    mamiferoPtr->Speak();               // Se llama a la versión de 'Speak' en la clase derivada

    delete mamiferoPtr;  // Destrucción polimórfica

    return 0;
}

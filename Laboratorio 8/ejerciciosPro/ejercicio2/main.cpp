#include <iostream>
#include <memory>
#include <string>

class Button {
public:
    virtual void Draw() const = 0;
    virtual ~Button() {}
};

class WinButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Windows\n";
    }
};

class MacButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Mac\n";
    }
};

class LinuxButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Linux\n";
    }
};

class GUIFactory {
public:
    virtual Button* CrearButton() const = 0;
    virtual ~GUIFactory() {}
};

class WinFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new WinButton();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new MacButton();
    }
};

class LinuxFactory : public GUIFactory {
public:
    Button* CrearButton() const override {
        return new LinuxButton();
    }
};

class Application {
private:
    std::unique_ptr<Button> button;

public:
    Application(const GUIFactory& factory, int os) {
        button.reset(factory.CrearButton());
        button->Draw();
    }
};

int main() {
    std::cout << "Cliente : Windows\n";
    WinFactory winFactory;
    Application app1(winFactory, 1);

    std::cout << "\nCliente : Mac\n";
    MacFactory macFactory;
    Application app2(macFactory, 2);

    std::cout << "\nCliente : Linux\n";
    LinuxFactory linuxFactory;
    Application app3(linuxFactory, 3);

    return 0;
}

#include <iostream>
#include <string>

class Recipe {
protected:
    std::string name;
    std::string ingredients;
    std::string origin;

public:
    virtual void prepareIngredients() = 0;
    virtual void cook() = 0;
    virtual void serve() = 0;
    virtual void showRecipe() = 0;
    virtual ~Recipe() {}
};

class Dessert : public Recipe {
public:
    Dessert() {
        name = "Tarta de Chocolate";
        ingredients = "Harina, huevos, chocolate, azucar";
        origin = "Francia";
    }
    void prepareIngredients() override {
        std::cout << "Preparando ingredientes para " << name << std::endl;
    }
    void cook() override {
        std::cout << "Horneando " << name << std::endl;
    }
    void serve() override {
        std::cout << "Sirviendo " << name << " en un plato decorado" << std::endl;
    }
    void showRecipe() override {
        std::cout << "Receta: " << name << std::endl
                  << "Ingredientes: " << ingredients << std::endl
                  << "Origen: " << origin << std::endl;
    }
};

class MainCourse : public Recipe {
public:
    MainCourse() {
        name = "Ceviche";
        ingredients = "Pescado, limon, cebolla, cilantro";
        origin = "Peru";
    }
    void prepareIngredients() override {
        std::cout << "Preparando ingredientes para " << name << std::endl;
    }
    void cook() override {
        std::cout << "Marinando el pescado para " << name << std::endl;
    }
    void serve() override {
        std::cout << "Sirviendo " << name << " con camote y choclo" << std::endl;
    }
    void showRecipe() override {
        std::cout << "Receta: " << name << std::endl
                  << "Ingredientes: " << ingredients << std::endl
                  << "Origen: " << origin << std::endl;
    }
};

class Drink : public Recipe {
public:
    Drink() {
        name = "Mojito";
        ingredients = "Ron, hierbabuena, limon, azucar";
        origin = "Cuba";
    }
    void prepareIngredients() override {
        std::cout << "Preparando ingredientes para " << name << std::endl;
    }
    void cook() override {
        std::cout << "Mezclando los ingredientes para " << name << std::endl;
    }
    void serve() override {
        std::cout << "Sirviendo " << name << " en un vaso con hielo" << std::endl;
    }
    void showRecipe() override {
        std::cout << "Receta: " << name << std::endl
                  << "Ingredientes: " << ingredients << std::endl
                  << "Origen: " << origin << std::endl;
    }
};

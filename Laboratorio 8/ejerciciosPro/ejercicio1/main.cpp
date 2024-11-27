#include <iostream>
#include "RecipeFactory.cpp"

int main() {
    int type;
    while (true) {
        std::cout << std::endl
                  << "Ingresa el tipo de receta: 1 (Postre), 2 (Plato Principal), 3 (Bebida), o 0 para salir." << std::endl;
        std::cin >> type;
        if (type == 0) {
            break;
        }
        Recipe* recipe = RecipeFactory::createRecipe(type);
        if (recipe) {
            recipe->showRecipe();
            delete recipe;
        }
    }
    std::cout << "Saliendo..." << std::endl;
    return 0;
}

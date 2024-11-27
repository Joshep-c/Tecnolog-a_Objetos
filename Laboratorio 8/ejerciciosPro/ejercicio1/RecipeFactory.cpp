#include "Recipe.cpp"

class RecipeFactory {
public:
    static Recipe* createRecipe(int type) {
        Recipe* recipe = nullptr;
        switch (type) {
        case 1:
            recipe = new Dessert;
            break;
        case 2:
            recipe = new MainCourse;
            break;
        case 3:
            recipe = new Drink;
            break;
        default:
            std::cout << "Tipo de receta no valido. Intenta otra opcion." << std::endl;
            return nullptr;
        }
        recipe->prepareIngredients();
        recipe->cook();
        recipe->serve();
        return recipe;
    }
};


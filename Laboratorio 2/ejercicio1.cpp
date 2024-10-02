#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class OperationAnalyzer {
public:
    // Función para analizar la operación
    void analyze(const std::string& expression) {
        std::vector<char> operators;
        std::vector<int> numbers;
        std::string temp = "";

        for (char ch : expression) {
            if (isdigit(ch)) {
                temp += ch;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (!temp.empty()) {
                    numbers.push_back(std::stoi(temp));
                    temp = "";
                }
                operators.push_back(ch);
            }
        }

        if (!temp.empty()) {
            numbers.push_back(std::stoi(temp));
        }

        if (numbers.size() > 6) {
            std::cerr << "Error: Se permiten como máximo 6 números." << std::endl;
            return;
        }

        std::cout << "Operadores: ";
        for (char op : operators) {
            std::cout << op << ' ';
        }
        std::cout << std::endl;

        std::cout << "Números: ";
        for (int num : numbers) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
};

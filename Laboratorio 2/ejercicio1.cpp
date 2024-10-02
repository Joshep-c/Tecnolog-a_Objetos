#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

// Clase que analiza la cadena de la operación
class OperationAnalyzer {
public:
    void analyze(const string& expression, vector<int>& numbers, vector<char>& operators) {
        string temp = "";

        for (char ch : expression) {
            if (isdigit(ch)) {
                temp += ch;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (!temp.empty()) {
                    numbers.push_back(stoi(temp));
                    temp = "";
                }
                operators.push_back(ch);
            }
        }

        if (!temp.empty()) {
            numbers.push_back(stoi(temp));
        }

        if (numbers.size() > 6) {
            cerr << "Error: Se permiten como máximo 6 números." << endl;
            numbers.clear();
            operators.clear();
        }
    }
};

// Clase que administra las operaciones matemáticas
class CalculatorCore {
public:
    int calculate(const vector<int>& numbers, const vector<char>& operators) {
        if (numbers.empty()) return 0;  // Si no hay números, retornar 0

        vector<int> resultNumbers = numbers;
        vector<char> resultOperators = operators;

        for (size_t i = 0; i < resultOperators.size(); ++i) {
            if (resultOperators[i] == '*' || resultOperators[i] == '/') {
                int num1 = resultNumbers[i];
                int num2 = resultNumbers[i + 1];
                int result = (resultOperators[i] == '*') ? num1 * num2 : num1 / num2;

                // Actualizar el vector con el resultado
                resultNumbers[i] = result;
                resultNumbers.erase(resultNumbers.begin() + i + 1);
                resultOperators.erase(resultOperators.begin() + i);
                i--;  // Volver a evaluar en la misma posición
            }
        }

        int result = resultNumbers[0];
        for (size_t i = 0; i < resultOperators.size(); ++i) {
            if (resultOperators[i] == '+') {
                result += resultNumbers[i + 1];
            } else if (resultOperators[i] == '-') {
                result -= resultNumbers[i + 1];
            }
        }

        return result;
    }
};

class CalculatorProcessor {
private:
    OperationAnalyzer analyzer;
    CalculatorCore core;

public:
    void process(const string& expression) {
        vector<int> numbers;
        vector<char> operators;

        analyzer.analyze(expression, numbers, operators);

        if (!numbers.empty()) {
            int result = core.calculate(numbers, operators);
            cout << "Resultado: " << result << endl;
        }
    }
};

int main() {
    CalculatorProcessor processor;
    string expression;

    cout << "Ingrese una operación (máx 6 números): ";
    cin >> expression;

    processor.process(expression);

    return 0;
}

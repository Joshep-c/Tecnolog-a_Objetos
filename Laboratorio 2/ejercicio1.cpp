#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class CalculatorCore {
public:
    int calculate(const string& expression) {
        vector<int> numbers;
        vector<char> operators;
        string temp = "";

        for (char ch : expression) {
            if (isdigit(ch)) {
                temp += ch;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                numbers.push_back(stoi(temp));
                temp = "";
                operators.push_back(ch);
            }
        }

        if (!temp.empty()) {
            numbers.push_back(stoi(temp));
        }

        int result = evaluatePriorityOperations(numbers, operators);
        return result;
    }

private:
    int evaluatePriorityOperations(vector<int>& numbers, vector<char>& operators) {
        stack<int> numStack;
        numStack.push(numbers[0]);

        for (size_t i = 0; i < operators.size(); ++i) {
            char op = operators[i];
            if (op == '*' || op == '/') {
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numbers[i + 1];
                int result = (op == '*') ? num1 * num2 : num1 / num2;
                numStack.push(result);
            } else {
                numStack.push(numbers[i + 1]);
            }
        }

        return evaluateRemaining(numStack, operators);
    }

    int evaluateRemaining(stack<int>& numStack, vector<char>& operators) {
        int result = numStack.top();
        numStack.pop();

        for (size_t i = 0; i < operators.size(); ++i) {
            if (operators[i] == '+' || operators[i] == '-') {
                int num = numStack.top();
                numStack.pop();
                result = (operators[i] == '+') ? result + num : result - num;
            }
        }

        return result;
    }
};

int main() {
    CalculatorCore core;
    string expression;

    cout << "Ingrese una operacion matematica (max 6 numeros): ";
    cin >> expression;

    int result = core.calculate(expression);
    cout << "Resultado: " << result << endl;

    return 0;
}

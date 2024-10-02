#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class OperationAnalyzer {
public:
    void analyze(const string& expression) {
        vector<char> operators;
        vector<int> numbers;
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
            cerr << "Error: Se permiten como maximo 6 numeros." << endl;
            return;
        }

        cout << "Operadores: ";
        for (char op : operators) {
            cout << op << ' ';
        }
        cout << endl;

        cout << "Numeros: ";
        for (int num : numbers) {
            cout << num << ' ';
        }
        cout << endl;
    }
};

int main() {
    OperationAnalyzer analyzer;
    string expression;

    cout << "Ingrese una operacion (max 6 numeros): ";
    cin >> expression;

    analyzer.analyze(expression);

    return 0;
}
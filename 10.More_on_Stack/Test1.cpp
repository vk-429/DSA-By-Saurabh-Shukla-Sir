#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> operands;

    for (char c : postfix) {
        if (std::isdigit(c)) { // Operand
            operands.push(c - '0'); // Convert char to integer
        } else if (c == ' ') {
            // Skip whitespace
        } else { // Operator
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        std::cerr << "Division by zero error\n";
                        return INT_MIN; // Handle error gracefully
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    std::cerr << "Invalid operator: " << c << "\n";
                    return INT_MIN; // Handle error gracefully
            }

            operands.push(result);
        }
    }

    if (operands.size() != 1) {
        std::cerr << "Invalid postfix expression\n";
        return INT_MIN; // Handle error gracefully
    }

    return operands.top();
}

int main() {
    std::string postfix = "23*5+";
    int result = evaluatePostfix(postfix);
    
    if (result != INT_MIN) {
        std::cout << "Postfix: " << postfix << "\n";
        std::cout << "Result: " << result << "\n";
    }

    return 0;
}

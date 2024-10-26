#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
// Function to parse the number from the string
int getNumber(const std::string& expr, int& pos) {
    int num = 0;
    while (pos < expr.length() && isdigit(expr[pos])) {
        num = num * 10 + (expr[pos] - '0');
        pos++;
    }
    return num;
}

int evaluateExpression(string& expr) {
    std::stack<int> values;   // Stack to store integer values
    std::stack<std::string> ops; // Stack to store operations ("add" or "subtract")
    
    int pos = 0;
    while (pos < expr.length()) {
        if (isdigit(expr[pos])) {
            // If it's a number, push it to the values stack
            values.push(getNumber(expr, pos));
        } 
        else if (expr[pos] == 'a' || expr[pos] == 's') {
            // If we encounter an "add" or "subtract", push it to the ops stack
            if (expr[pos] == 'a') {
                ops.push("add");
                pos += 4; // Skip "add("
            } else {
                ops.push("subtract");
                pos += 9; // Skip "subtract("
            }
        } 
        else if (expr[pos] == ',') {
            // Skip commas
            pos++;
        } 
        else if (expr[pos] == ')') {
            // When we hit a closing parenthesis, we perform the operation
            int second = values.top(); values.pop();
            int first = values.top(); values.pop();
            std::string operation = ops.top(); ops.pop();

            if (operation == "add") {
                values.push(first + second);
            } else if (operation == "subtract") {
                values.push(first - second);
            }
            
            pos++;
        } 
        else {
            pos++; // Skip any other characters like spaces (though spaces are not expected here)
        }
    }

    // The result will be the only value left in the stack
    return values.top();
}

int main() {
    std::string input;
    std::cout << "Enter the expression: ";
    std::getline(std::cin, input);

    int result = evaluateExpression(input);
    std::cout << "Output: " << result << std::endl;

    return 0;
}

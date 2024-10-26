#include<iostream>
using namespace std;
#include <iostream>
#include <string>
#include <cctype>

int evaluateExpression(string expr, int& pos);

int getNumber(string& expr, int& pos) {
    int num = 0;
    while (pos < expr.length() && isdigit(expr[pos])) {
        num = num * 10 + (expr[pos] - '0');
        pos++;
    }
    return num;
}

// Function to evaluate 'add' and 'subtract' expressions
int evaluateFunction(string& expr, int& pos) {
    string funcName;
    // Extract function name (either "add" or "subtract")
    while (pos < expr.length() && isalpha(expr[pos])) {
        funcName += expr[pos];
        pos++;
    }
    
    // Skip the opening parenthesis '('
    pos++;

    // Evaluate the first argument
    int arg1 = evaluateExpression(expr, pos);

    // Skip the comma ','
    pos++;

    // Evaluate the second argument
    int arg2 = evaluateExpression(expr, pos);

    // Skip the closing parenthesis ')'
    pos++;

    // Perform the required operation
    if (funcName == "add") {
        return arg1 + arg2;
    } else if (funcName == "subtract") {
        return arg1 - arg2;
    }

    return 0; // Default return (should not reach here)
}

// Function to evaluate expression based on type (number or function)
int evaluateExpression(std::string expr, int& pos) {
    if (isdigit(expr[pos])) {
        // If it's a number, extract the number
        return getNumber(expr, pos);
    } else {
        // If it's a function, evaluate the function
        return evaluateFunction(expr, pos);
    }
}

int main() {
    string input;
    cout << "Enter the expression: ";
    getline(cin, input);

    int pos = 0;
    int result = evaluateExpression(input, pos);

    cout << "Output: " << result << std::endl;
    return 0;
}

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
bool isRightAssociative(char op) {
    return op == '^';
}
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
string infixToPostfix(string expr) {
    stack<char> opStack;
    string postfix = "";
    bool mismatchError = false;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == ' ') continue;
        if (isdigit(ch) || ch == '.') {
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                postfix += expr[i];
                i++;
            }
            i--; 
            postfix += ' ';  
        }
        else if (ch == '(') {
            opStack.push(ch);
        }
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            if (opStack.empty()) {
                return "ERROR: Mismatched parentheses";
            }
            opStack.pop();  
        }
        else if (isOperator(ch)) {
            while (!opStack.empty() && opStack.top() != '(' &&
                   (precedence(opStack.top()) > precedence(ch) ||
                    (precedence(opStack.top()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += opStack.top();
                postfix += ' ';
                opStack.pop();
            }
            opStack.push(ch);
        }
        else {
            return "ERROR: Invalid character '" + string(1, ch) + "'";
        }
    }
    while (!opStack.empty()) {
        if (opStack.top() == '(') {
            return "ERROR: Mismatched parentheses";
        }
        postfix += opStack.top();
        postfix += ' ';
        opStack.pop();
    }
    return postfix;
}
double evaluatePostfix(string postfix) {
    stack<double> numStack;
    string token = "";
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (ch == ' ') {
            if (!token.empty()) {
                bool hasDigit = false;
                bool hasDot = false;
                for (int j = 0; j < token.length(); j++) {
                    if (isdigit(token[j])) hasDigit = true;
                    if (token[j] == '.') {
                        if (hasDot) return NAN;  
                        hasDot = true;
                    }
                }
                if (!hasDigit) return NAN;
                double num = stod(token);
                numStack.push(num);
                token = "";
            }
            continue;
        }
        if (isOperator(ch)) {
            if (numStack.size() < 2) return NAN;
            double b = numStack.top(); numStack.pop();
            double a = numStack.top(); numStack.pop();
            double result;
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) return NAN; 
                    result = a / b;
                    break;
                case '^': result = pow(a, b); break;
                default:  return NAN;
            }
            numStack.push(result);
        }
        else {
            token += ch;
        }
    }
    if (!token.empty()) {
        numStack.push(stod(token));
    }
    if (numStack.size() != 1) return NAN;
    return numStack.top();
}
void printSeparator() {
    cout << "----------------------------------------\n";
}
int main() {
    cout << "========================================\n";
    cout << "       EXPRESSION EVALUATOR\n";
    cout << "========================================\n\n";
    cout << "  Supported operators: + - * / ^\n";
    cout << "  Supports: parentheses, multi-digit\n";
    cout << "            numbers, floating point\n\n";
    cout << "  Type \"exit\" to quit\n\n";
    string expr;
    while (true) {
        printSeparator();
        cout << "  Enter infix expression: ";
        getline(cin, expr);
        if (expr == "exit") break;
        if (expr.empty()) continue;
        string postfix = infixToPostfix(expr);
        if (postfix.find("ERROR") != string::npos) {
            cout << "\n  " << postfix << "\n";
            continue;
        }
        cout << "\n  Postfix: " << postfix << "\n";
        double result = evaluatePostfix(postfix);
        if (isnan(result)) {
            cout << "  Result:  Error (invalid expression or division by zero)\n";
        } else {
            if (result == (int)result) {
                cout << "  Result:  " << (int)result << "\n";
            } else {
                cout << "  Result:  " << result << "\n";
            }
        }
    }
    cout << "\n  Goodbye!\n";
    return 0;
}
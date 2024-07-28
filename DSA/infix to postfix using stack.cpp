#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> stk;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop(); // Pop '(' from the stack
        } else if (isOperator(c)) {
            while (!stk.empty() && precedence(c) <= precedence(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "The equivalent postfix expression is: " << postfix << endl;

    return 0;
}


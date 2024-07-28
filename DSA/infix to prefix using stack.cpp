#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
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

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    stack<char> stk;
    string prefix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix += c;
        } else if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                prefix += stk.top();
                stk.pop();
            }
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            }
        } else if (isOperator(c)) {
            while (!stk.empty() && precedence(c) < precedence(stk.top())) {
                prefix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while (!stk.empty()) {
        prefix += stk.top();
        stk.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "The equivalent prefix expression is: " << prefix << endl;

    return 0;
}


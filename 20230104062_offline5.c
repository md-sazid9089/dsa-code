#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 5;
    if (c == '*' || c == '/') return 4;
    if (c == '+' || c == '-') return 3;
    return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char symbol = infix[i];

        if (isdigit(symbol)) {
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if (symbol == '(') {
            s.push(symbol);
        }
        else if (symbol == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOperator(symbol)) {
            while (!s.empty() && precedence(symbol) <= precedence(s.top()) && symbol != '^') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> s;
    int num = 0;
    bool isBuildingNumber = false;

    for (int i = 0; i < postfix.length(); i++) {
        char symbol = postfix[i];

        if (isdigit(symbol)) {
            num = num * 10 + (symbol - '0');
            isBuildingNumber = true;
        }
        else if (symbol == ' ' && isBuildingNumber) {
            s.push(num);
            num = 0;
            isBuildingNumber = false;
        }
        else if (isOperator(symbol)) {
            if (s.size() < 2) {
                cout << "Error: Not enough operands\n";
                return -1;
            }
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            switch (symbol) {
                case '^': s.push(pow(b, a)); break;
                case '*': s.push(b * a); break;
                case '/':
                    if (a == 0) {
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    s.push(b / a);
                    break;
                case '+': s.push(b + a); break;
                case '-': s.push(b - a); break;
            }
        }
    }

    return s.size() == 1 ? s.top() : -1;
}

int main() {
    string infix;
    cout << "Input infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        cout << "Value: " << result << endl;
    }

    return 0;
}

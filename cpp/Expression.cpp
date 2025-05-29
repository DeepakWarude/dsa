#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 100;
class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack() {
        top = -1;
    }
    void push(char ch) {
        if (top < MAX - 1) {
            top++;
            arr[top] = ch;
        }
    }
    char pop() {
        if (top >= 0) {
            char temp = arr[top];
            top--;
            return temp;
        }
        return '\0';
    }
    char peek() {
        if (top >= 0) {
            return arr[top];
        }
        return '\0';
    }
    bool empty() {
        if (top == -1)
            return true;
        else
            return false;
    }
};

// Stack for strings
class StringStack {
    string arr[MAX];
    int top;
public:
    StringStack() {
        top = -1;
    }

    void push(string str) {
        if (top < MAX - 1) {
            top++;
            arr[top] = str;
        }
    }

    string pop() {
        if (top >= 0) {
            string temp = arr[top];
            top--;
            return temp;
        }
        return "";
    }

    string peek() {
        if (top >= 0) {
            return arr[top];
        }
        return "";
    }

    bool empty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    int size() {
        return top + 1;
    }
};

// Stack for integers
class IntStack {
    int arr[MAX];
    int top;
public:
    IntStack() {
        top = -1;
    }

    void push(int val) {
        if (top < MAX - 1) {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (top >= 0) {
            int temp = arr[top];
            top--;
            return temp;
        }
        return 0;
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        return 0;
    }

    bool empty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    int size() {
        return top + 1;
    }
};

class Expression {
public:
    void infix_to_prefix() {
        string infix, prefix = "";
        cout << "Enter infix expression: ";
        cin >> infix;

        if (!is_valid_infix(infix)) {
            cout << "Invalid infix expression.\n";
            return;
        }

        reverse(infix.begin(), infix.end());
        for (int i = 0; i < infix.length(); i++) {
            if (infix[i] == '(')
                infix[i] = ')';
            else if (infix[i] == ')')
                infix[i] = '(';
        }

        CharStack s;
        for (int i = 0; i < infix.length(); i++) {
            char ch = infix[i];
            if (isalpha(ch)) {
                prefix = ch + prefix;
            } else if (ch == '(') {
                s.push(ch);
            } else if (ch == ')') {
                while (!s.empty() && s.peek() != '(') {
                    prefix = s.pop() + prefix;
                }
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                while (!s.empty() && precedence(s.peek()) >= precedence(ch)) {
                    prefix = s.pop() + prefix;
                }
                s.push(ch);
            }
        }

        while (!s.empty()) {
            prefix = s.pop() + prefix;
        }

        cout << "Prefix expression: " << prefix << endl;
    }

    void prefix_to_infix() {
        string prefix;
        cout << "Enter prefix expression: ";
        cin >> prefix;

        if (!is_valid_prefix(prefix)) {
            cout << "Invalid prefix expression.\n";
            return;
        }

        StringStack s;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char ch = prefix[i];
            if (isalpha(ch)) {
                s.push(string(1, ch));
            } else if (is_operator(ch)) {
                string op1 = s.pop();
                string op2 = s.pop();
                s.push("(" + op1 + ch + op2 + ")");
            }
        }

        cout << "Infix expression: " << s.peek() << endl;
    }

    void postfix_to_infix() {
        string postfix;
        cout << "Enter postfix expression: ";
        cin >> postfix;

        if (!is_valid_postfix(postfix)) {
            cout << "Invalid postfix expression.\n";
            return;
        }

        StringStack s;
        for (int i = 0; i < postfix.length(); i++) {
            char ch = postfix[i];
            if (isalpha(ch)) {
                s.push(string(1, ch));
            } else if (is_operator(ch)) {
                string op2 = s.pop();
                string op1 = s.pop();
                s.push("(" + op1 + ch + op2 + ")");
            }
        }

        cout << "Infix expression: " << s.peek() << endl;
    }

    void expressionEvaluate() {
        string postfix;
        cout << "Enter postfix expression (digits only, no spaces): ";
        cin >> postfix;

        IntStack s;
        for (int i = 0; i < postfix.length(); i++) {
            char ch = postfix[i];
            if (isdigit(ch)) {
                s.push(ch - '0');
            } else if (is_operator(ch)) {
                if (s.size() < 2) {
                    cout << "Invalid postfix expression.\n";
                    return;
                }
                int b = s.pop();
                int a = s.pop();
                int res = 0;

                if (ch == '+') res = a + b;
                else if (ch == '-') res = a - b;
                else if (ch == '*') res = a * b;
                else if (ch == '/') {
                    if (b == 0) {
                        cout << "Division by zero error.\n";
                        return;
                    }
                    res = a / b;
                } else if (ch == '^') res = pow(a, b);
                else {
                    cout << "Unknown operator.\n";
                    return;
                }
                s.push(res);
            } else {
                cout << "Invalid character in expression.\n";
                return;
            }
        }

        if (s.size() != 1) {
            cout << "Invalid postfix expression.\n";
            return;
        }

        cout << "Result is: " << s.peek() << endl;
    }

    int precedence(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '^') return 3;
        return 0;
    }

    bool is_operator(char ch) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            return true;
        else
            return false;
    }

    bool is_valid_infix(string expr) {
        int balance = 0;
        bool lastWasOperand = false;
        bool lastWasOperator = true;

        for (int i = 0; i < expr.length(); i++) {
            char ch = expr[i];
            if (isalpha(ch)) {
                if (lastWasOperand) return false;
                lastWasOperand = true;
                lastWasOperator = false;
            } else if (is_operator(ch)) {
                if (lastWasOperator) return false;
                lastWasOperand = false;
                lastWasOperator = true;
            } else if (ch == '(') {
                balance++;
                lastWasOperator = true;
            } else if (ch == ')') {
                balance--;
                if (balance < 0 || lastWasOperator) return false;
            } else {
                return false;
            }
        }

        if (balance != 0 || lastWasOperator) return false;
        return true;
    }

    bool is_valid_prefix(string expr) {
        int count = 0;
        for (int i = expr.length() - 1; i >= 0; i--) {
            char ch = expr[i];
            if (isalpha(ch)) count++;
            else if (is_operator(ch)) {
                if (count < 2) return false;
                count--;
            } else {
                return false;
            }
        }
        if (count == 1) return true;
        return false;
    }

    bool is_valid_postfix(string expr) {
        int count = 0;
        for (int i = 0; i < expr.length(); i++) {
            char ch = expr[i];
            if (isalpha(ch)) count++;
            else if (is_operator(ch)) {
                if (count < 2) return false;
                count--;
            } else {
                return false;
            }
        }
        if (count == 1) return true;
        return false;
    }
};

int main() {
    Expression exp;
    int choice;

    do {
        cout << "\n*** Select An Option ***";
        cout << "\n1. Infix to Prefix";
        cout << "\n2. Prefix to Infix";
        cout << "\n3. Postfix to Infix";
        cout << "\n4. Expression Evaluation for Postfix (Numbers)";
        cout << "\n5. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) exp.infix_to_prefix();
        else if (choice == 2) exp.prefix_to_infix();
        else if (choice == 3) exp.postfix_to_infix();
        else if (choice == 4) exp.expressionEvaluate();
        else if (choice == 5) cout << "Exiting...\n";
        else cout << "Invalid choice! Please enter 1 to 5.\n";

    } while (choice != 5);

    return 0;
}

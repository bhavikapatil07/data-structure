#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}
int performOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}
int evaluatePostfix(string postfix) {
    stack<int> st; 
  for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            st.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(performOperation(a, b, ch));
        }
    }

    return st.top();
}

int main() {
    string postfix = "23+4*5-";
    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return -1;
}
string infixToPostfix(string infix) {
    stack<char> st; 
    string ans = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isalnum(ch))
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string infix = "a+b*(c+d)-e/f";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}

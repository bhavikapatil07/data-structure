#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
    private:
        stack<int> st;
    public:
        bool isEmpty(){
            return st.empty();
        }

        bool isFull(){
            return st.size() == MAX_SIZE;
        }

        void push(int value){
            if(isFull()){
                cout << "Stack Overflow. Cannot push " << value << ". Stack is full." << endl;
            } else {
                st.push(value);
                cout << value << " pushed to the stack." << endl;
            }
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack Underflow. Cannot pop from an empty stack." << endl;
            } else {
                cout << st.top() << " popped from the stack." << endl;
                st.pop();
            }
        }

        void display(){
            if(isEmpty()){
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack elements: ";
                stack<int> temp = st;
                while(!temp.empty()){
                    cout << temp.top() << " ";
                    temp.pop();
                }
                cout << endl;
            }
        }
};

int main(){
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    cout << endl;

    stack.display();

    cout << endl;

    stack.pop();
    stack.display();

    cout << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); 

    return 0;
}

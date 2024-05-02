#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
    private:
        int front, rear, arr[MAX_SIZE];
    public:
        Queue(){
            front = rear = -1;
        }

        bool isEmpty(){
            return front == -1 && rear == -1;
        }

        bool isFull(){
            return rear == MAX_SIZE -1;
        }

        void enqueue(int value){
            if(isFull()){
                cout << "Queue Overflow. Cannot enqueue " << value << ". Queue is full." << endl;
            } else {
                if(isEmpty()){
                    front = 0;
                }
                arr[++rear] = value;
                cout << value << " enqueued to the queue." << endl;
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue Underflow. Cannot dequeue from an empty queue." << endl;
            } else {
                int dequeuedValue = arr[front++];
                cout << dequeuedValue << " dequeued from the queue." << endl;

                if(front > rear){
                    // Rest the front and rear element when the last element is dequeued.
                    front = rear = -1;
                }
            }
        }

        void display(){
            if(isEmpty()){
                cout << "Queue is empty." << endl;
            } else {
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Queue queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);

    cout << endl;

    queue.display();
    
    cout << endl;

    queue.dequeue();
    queue.display();

    cout << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // This will result in an queue underflow
}

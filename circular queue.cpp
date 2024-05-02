#include <iostream>
#define SIZE 5 // Size of Circular Queue

using namespace std;

class Queue {
private:
    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            return true;
        }
        return false;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert an element into the circular queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "The circular queue is full." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        items[rear] = data;
    }

    // Delete an element from the circular queue
    int dequeue() {
        if (isEmpty()) {
            cout << "The circular queue is empty." << endl;
            return -1;
        }
        int temp = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return temp;
    }

    // Display the circular queue
    void display() {
        if (isEmpty()) {
            cout << "No element in the circular queue." << endl;
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; ++i) {
                cout << items[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; ++i) {
                cout << items[i] << " ";
            }
            for (int i = 0; i <= rear; ++i) {
                cout << items[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Queue cq;
    int choice, data;

    do {
        cout << "Circular Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                cq.enqueue(data);
                break;
            case 2:
                cout << "Dequeued element: " << cq.dequeue() << endl;
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Incorrect choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

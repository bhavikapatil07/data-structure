#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head; 
public:
    LinkedList() {
        head = nullptr;
    }
    void create(int value) {
        head = new Node(value);
    }
    void insert(int value) {
        if (head == nullptr) {
            create(value);
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }
    void remove(int value) {
        if (head == nullptr) {
            cout << "Linked list is empty. Cannot delete from an empty list." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " deleted from the list." << endl;
            return;
        }
        Node* prev = head;
        while (prev->next != nullptr && prev->next->data != value) {
            prev = prev->next;
        }
        if (prev->next == nullptr) {
            cout << "Node with value " << value << " not found in the list." << endl;
            return;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        cout << "Node with value " << value << " deleted from the list." << endl;
    }
    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
        } else {
            Node* temp = head;
            cout << "Linked list elements: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main() {
    LinkedList linkedList;

    linkedList.create(5);
    linkedList.insert(10);
    linkedList.insert(15);
    linkedList.insert(20);

    cout << endl;

    linkedList.display();

    cout << endl;

    linkedList.remove(10);
    linkedList.display();

    cout << endl;

    linkedList.remove(22);

    return 0;
}


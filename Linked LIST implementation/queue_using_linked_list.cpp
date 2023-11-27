#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    
};
class Queue {
    public:
    Node* front;
    Node* rear;
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int);
    void dequeue();
    void peek();
    bool is_empty();
};
void Queue::enqueue(int data) {
    Node* new_node = new Node(data);
    if(rear == NULL) {
        front = new_node;
        rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}
void Queue::dequeue() {
    Node* temp = front;
    if(front == NULL) {
        cout << "Queue Underflow \n";
        return;
    }
    front = front->next;
    if(front == NULL) {
        rear = NULL;
    }
    delete temp;
}
void Queue::peek() {
    if(front == NULL) {
        cout << "No element to show \n";
        return;
    }
    cout << front->data << endl;
}
bool Queue::is_empty() {
    return front == NULL;
}
main() {
    Queue q1;
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(10);
    q1.enqueue(18);
    q1.peek();
    q1.dequeue();
    q1.peek();
    q1.dequeue();
    q1.peek();
    q1.dequeue();
    q1.peek();
    q1.dequeue();
    q1.dequeue();
    q1.peek();
    cout << q1.is_empty();
}
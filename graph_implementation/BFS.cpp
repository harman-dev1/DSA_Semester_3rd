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
    int peek();
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

int Queue::peek() {
    if(front == NULL) {
        cout << "No element to show \n";
        return -1;
    }
    return front->data;
}

bool Queue::is_empty() {
    return front == NULL;
}

void BFS(int m[][7], int start) {
    int i = start;
    Queue q1;
    int visited[7] = {0};
    cout << i << " ";
    visited[i] = 1;
    q1.enqueue(i);
    while(!(q1.is_empty())) {
        i = q1.peek();

        q1.dequeue();
        for(int j = 1;j < 7;j++) {
            if(m[i][j] == 1 && visited[j] == 0) {
                cout << j << " ";
                visited[j] = 1;
                q1.enqueue(j);
            }
        }

    }
}

main() {
    int m[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0}, 
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    BFS(m,4);
}
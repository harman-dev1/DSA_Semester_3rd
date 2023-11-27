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
class Stack {
    Node* top;
    public:
    Stack() {
        top = NULL;
    }
    void push(int);
    void peek();
    void pop();
    bool empty();
    void display();
};
void Stack::push(int data) {
    Node* new_node = new Node(data);
    if(new_node == NULL) {
        cout << "Stack Overflow\n";
        return;
    }
    new_node->next = top; 
    top = new_node;

}
void Stack::pop() {
    if(top == NULL) {
        cout << "No Element to Pop\n";
        return;
    }
    Node* pop_node = top;
    top = top->next;
    delete pop_node;
}
void Stack::peek() {
    if(top == NULL) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << top->data << "\n";
}
bool Stack::empty() {
    return top == NULL;
}
void Stack::display() {
    Node* temp = top;
    if(temp == NULL) {
        cout << "Stack is Underflow";
        return;
    }
    while(temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
}
main() {
    Stack s1;
    s1.push(8);
    s1.push(12);
    s1.push(13);
    s1.push(16);
    s1.push(18);
    //s1.push(1);
    //s1.peek();
    //s1.pop();
    //s1.peek();
    //s1.pop();
    //s1.peek();
    s1.display();
}
#include<iostream>
using namespace std;
class Node {
    public:
    string data;
    Node* next;
    Node() {
        this->next = NULL;
    }
    Node(string data) {
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
    void push(string);
    void display();
};
void Stack::push(string data) {
    Node* new_node = new Node(data);
    if(new_node == NULL) {
        cout << "Stack Overflow\n";
        return;
    }
    new_node->next = top; 
    top = new_node;

}
void Stack::display() {
    Node* temp = top;
    if(temp == NULL) {
        cout << "Stack is Underflow";
        return;
    }
    while(temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
}
main() {
    string word = "I am from University of Engineering and Technology Lahore";
    string split_word = "";
    Stack s1;
    for(int i = 0; i < word.length();i++) {
        if(word[i] != ' ') {
            split_word += word[i]; 
        } 
        else if(word [i] == ' ') {
            split_word += " ";
            s1.push(split_word);
            split_word = "";
        }   
    }
    s1.push(split_word);
    s1.display();
}
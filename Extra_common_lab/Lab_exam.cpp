#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class linked_list {
    public:
    Node* head;
    linked_list() {
        head = NULL;
    }
    Node* insert_node_at_end(int);
    void print_node(Node*);
};

Node* linked_list::insert_node_at_end(int data) {
    Node* new_node = new Node(data);
    if(head == NULL) {
        head = new_node;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
} 

void linked_list:: print_node(Node* head)
{
    Node* temp;
    temp = head;
    if (head == NULL)
    {
        cout << "LIst is Empty";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
} 

main() {
    linked_list l1;
    l1.head = l1.insert_node_at_end(7);
    l1.head = l1.insert_node_at_end(7);
    l1.head = l1.insert_node_at_end(7);
    l1.head = l1.insert_node_at_end(7);
    l1.head = l1.insert_node_at_end(7);
    l1.print_node(l1.head);
}
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* previous;
    Node(){
        this->next = NULL;
        this->previous = NULL;
        this->data = 0;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};
class doubly_linked_list
{
    Node* head;
    public:
    doubly_linked_list(){
        this->head = NULL;
    }
    void insert_node_at_tail(int);
    void print_doubly_link_list();
    void insert_node_at_head(int);
    void insert_node_at_specific_index(int,int);
    void delete_node(int);
    void delete_node_at_tail();
    void delete_node_at_head();
    bool find_node(int);
};
void doubly_linked_list::insert_node_at_specific_index(int index,int data)
{
    Node* new_node = new Node(data);
    Node* temp = head;
    int count = 0;
    while(count != index && temp->next != NULL){
        count += 1;
        temp = temp->next;
    }
    temp->previous->next = new_node;
    new_node->next = temp;
    new_node->previous = temp->previous;
    temp->previous = new_node;
}
void doubly_linked_list::insert_node_at_head(int data)
{
    Node* new_node = new Node(data);
    new_node->next = head;
    if (head != NULL){
        head->previous = new_node;
    }
    head = new_node;

}
void doubly_linked_list::insert_node_at_tail(int data)
{
    Node* new_node = new Node(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->previous = temp;

}
bool doubly_linked_list::find_node(int key){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->previous;
    }
    return false;
}
void doubly_linked_list::delete_node(int val)
{
    Node* temp = head;
    while(temp->data != val){
        temp = temp->next;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;
}
void doubly_linked_list::delete_node_at_tail()
{
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->previous->next = NULL;
    delete temp;
}
void doubly_linked_list::delete_node_at_head()
{
    if(head == NULL){
        cout << "Empty List";
        return;
    }
    Node* temp = head;
    head= head->next;
    head->previous = NULL;
    delete temp;
}
void doubly_linked_list::print_doubly_link_list()
{
    Node* temp;
    temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<"\n";
}
main()
{
    doubly_linked_list d1;
    d1.insert_node_at_tail(8);
    d1.insert_node_at_tail(7);
    d1.insert_node_at_tail(27);
    d1.insert_node_at_tail(20);
    d1.insert_node_at_tail(1);
    d1.insert_node_at_tail(2);
    //d1.print_doubly_link_list();
    d1.insert_node_at_head(10);
    //d1.print_doubly_link_list();
    d1.delete_node(2);
    // d1.print_doubly_link_list();
    //d1.delete_node_at_tail();
    //d1.print_doubly_link_list();
    //d1.delete_node_at_head();
    //d1.print_doubly_link_list();
    //d1.insert_node_at_specific_index(4,81);
    d1.print_doubly_link_list();
    bool flag = d1.find_node(10);
    if(flag == true){
        cout << "Value Found";
    }
    else{
        cout << "Not found 404!!!";
    }
}
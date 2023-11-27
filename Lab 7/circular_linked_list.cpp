#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class circular_linked_list{
    Node* head;
    public:
    circular_linked_list(){
        this->head = NULL;
    }
    void insert_node_at_tail(int);
    void insert_node_at_head(int);
    void insert_at_specific_index(int,int);
    void delete_tail_node();
    void display_circular_likned_list();
    void delete_head_node();
    void delete_specific_node(int);
    bool find_node(int);
};
void circular_linked_list::insert_at_specific_index(int index,int data){
    Node* temp = head;
    int count = 0;
    if(count == index){
        insert_node_at_head(5);
        return;
    }
    while(count != (index-1)){
        count += 1;
        temp = temp->next;
    }
    Node* new_node = new Node(5);
    new_node->next = temp->next;
    temp->next = new_node;
}
void circular_linked_list::insert_node_at_head(int data){
    Node* new_node = new Node(data);
    Node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next != head);
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
}
void circular_linked_list::insert_node_at_tail(int data){
    Node* new_node = new Node(data);
    if (head ==  NULL){
        head = new_node;
        head->next = head;
        return;
    }
    Node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next != head);
    temp->next = new_node;
    new_node->next = head; 
}
bool circular_linked_list::find_node(int key){
    Node* temp = head;
    do{
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }while(temp != head); 
    return false;
}
void circular_linked_list::delete_tail_node(){
    Node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next->next != head);
    Node* temp2 = temp->next;
    temp->next = head;
    delete temp2;
}
void circular_linked_list::delete_head_node(){
    Node* temp = head;
    Node* temp2 = head;
    do{
        temp = temp->next;
    }while(temp->next != head);
    head = head->next;
    temp->next = head;
    delete temp2;
}
void circular_linked_list::delete_specific_node(int val){
    Node* temp = head;
    do{
        temp = temp->next;
    }while(temp->next->data != val);
    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    head = temp->next;
    delete temp2;
}
void circular_linked_list::display_circular_likned_list(){
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << "\n";
}
main()
{
    circular_linked_list c1;
    c1.insert_node_at_tail(7);
    c1.insert_node_at_tail(8);
    c1.insert_node_at_tail(12);
    c1.insert_node_at_tail(20);
    c1.insert_node_at_head(27);
    //c1.display_circular_likned_list();
    //c1.delete_tail_node();
    //c1.delete_head_node();
    //c1.delete_specific_node(27);
    c1.insert_at_specific_index(5,5);
    c1.display_circular_likned_list();
    bool flag = c1.find_node(200);
    if (flag == true){
        cout << "Value Found";
    }
    else{
        cout << "Value Not Found";
    }
}
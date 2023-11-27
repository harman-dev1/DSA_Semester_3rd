#include<iostream>
using namespace std;

//Class for creating node that consists of data and pointer
class Node{
    public:
    int data;
    Node* next;
    Node(){
        next = NULL;
        data = 0;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//Class consists of head and multiple operations that can be apply on link_list
class linked_list{
    Node* head;
    public:
    linked_list(){
        this->head = NULL;
    }
    void insert_node_at_end(int);
    void print_node();
    void insert_node_at_first(int);
    bool is_empty();
    void delete_node(int);
    void delete_last_node();
    void delete_first_node();
    void insert_node_at_specific_index(int,int);
    bool find_node(int);
    Node* reverseList();
    Node* sort_list();
    Node* remove_duplicates();
};
Node* linked_list::remove_duplicates(){
    Node* p = head;
    Node* q = p->next;
    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
Node* linked_list::sort_list(){
    int count = 0;
    Node* c_temp = head;
    while(c_temp != NULL){
        count +=1;
        c_temp = c_temp->next;
    }
    Node* temp = head;
    Node* temp2 = head;
    int swap;
    if(temp->next == NULL){
        return temp;
    }
    for(int i = 0;temp->next != NULL;temp = temp->next,i++){
        temp2 = head;
        for(int j = 0; j < count-1-i ;j++){
            if(temp2->data > temp2->next->data){
                swap = temp2->data;
                temp2->data = temp2->next->data;
                temp2->next->data = swap;
            }
            temp2 = temp2->next;
        }
    }
}
Node* linked_list::reverseList(){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count +=1;
        temp = temp->next;
    }
    Node* temp2 = head;
    int* arr = new int[count];
    for(int i = 0; i < count; i++){
        arr[i] = temp2->data;
        temp2 = temp2->next;
    }
    temp = head;
    for(int i = count-1;i > -1; i--){
        temp->data = arr[i];
        temp = temp->next;
    }
}
//Function for deleting Head Node 
void linked_list::delete_first_node()
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

//Function for deleting Tail Node 
void linked_list::delete_last_node()
{
    int len_of_llist = 0;
    Node* temp = head;
    while(temp->next != NULL)
    {
        len_of_llist += 1;
        temp = temp->next;
    }
    Node* temp2 = head;
    int count = 1;
    while(count < len_of_llist)
    {
        temp2 = temp2->next;
        count += 1;
    }
    temp2->next = NULL;
    delete temp;
}

//Function for deleting Any Node except Head node 
void linked_list::delete_node(int value)
{
    Node* temp = head;
    while(temp->next->data != value)
    {
        temp = temp->next;
    }
    Node* d_node = temp->next;
    temp->next = temp->next->next;
    delete d_node;
}

//Function to check link list is empty or not
bool linked_list::is_empty()
{
    return head == NULL;
}

//Function for inserting Node at tail
void linked_list:: insert_node_at_end(int data)
{
    Node* new_node = new Node(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
//Function for inserting node at any index
void linked_list::insert_node_at_specific_index(int index,int data)
{
    Node* new_node = new Node(data);
    Node* temp = head;
    int count = 0;
    while(count != (index-1) && temp->next != NULL){
        count += 1;
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

//Function for Inserting Node at Head 
void linked_list::insert_node_at_first(int data)
{
    Node* new_node = new Node(data);
    if (head == NULL){
        head = new_node;
        return;
    }
    Node* temp = new_node;
    temp->next = head;
    head = temp; 
}

bool linked_list::find_node(int key){
    Node* temp = head;
    Node* temp2 = head;
    while(temp != NULL){
        if (key == temp->data){
           temp2->next = temp->next;
           temp->next = head;
           head = temp;
           return true;
        }
        temp2 = temp;
        temp = temp->next;
    }
    return false;

}
//Function for displaying link_list 
void linked_list:: print_node()
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

//Driver Code
main()
{
    linked_list l1;
    l1.insert_node_at_end(55);
    l1.insert_node_at_first(8);
    l1.insert_node_at_end(3);
    l1.insert_node_at_end(22);
    l1.insert_node_at_end(21);
    l1.insert_node_at_end(25);
    l1.insert_node_at_end(5);
    l1.insert_node_at_first(3);
    //l1.delete_node(14);
    //l1.delete_last_node();
    //l1.print_node();
    //l1.delete_first_node();
    //l1.print_node();
    l1.insert_node_at_specific_index(2,7);
    l1.print_node(); 
    //bool flag = l1.find_node(10);
    // //if (flag != true){
    //     cout << "Value Found ";
    // }    
    // else{
    //     cout << "404 Not Found!!!";
    // }   
    //cout << l1.is_empty();
    //l1.reverseList();
    l1.sort_list();
    l1.print_node();
    l1.remove_duplicates();
    l1.print_node();
}
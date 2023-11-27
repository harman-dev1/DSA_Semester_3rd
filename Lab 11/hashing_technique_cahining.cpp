#include <iostream>
using namespace std;

// Class for creating node that consists of data and pointer
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
        data = 0;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Hash_Table
{
public:
    Node **HT;
    Hash_Table()
    {
        HT = new Node *[10];
        for (int i = 0; i < 10; i++)
        {
            HT[i] = NULL;
        }
    }
    int hash(int);
    void insert(int);
    int search(int);
    int delete_from_hash_table(int);
    void print_hash_table();
};

int Hash_Table::hash(int key)
{
    return key % 10;
}

void Hash_Table::insert(int key)
{
    int hash_table_index = hash(key);
    Node *new_node = new Node(key);
    if (HT[hash_table_index] == NULL)
    {
        HT[hash_table_index] = new_node;
    }
    else
    {
        Node *p = HT[hash_table_index];
        Node *q = HT[hash_table_index];
        while (p != NULL && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if (q == HT[hash_table_index] && key <= q->data)
        {
            new_node->next = q;
            HT[hash_table_index] = new_node;
        }
        else
        {
            new_node->next = q->next;
            q->next = new_node;
        }
    }
}

int Hash_Table::search(int key)
{
    int hash_table_index = hash(key);
    Node *p = HT[hash_table_index];
    while (p && key >= p->data)
    {
        if (p->data == key)
        {
            return key;
        }
        p = p->next;
    }
    return -1;
}

int Hash_Table::delete_from_hash_table(int key)
{
    int hash_table_index = hash(key);
    Node *temp = HT[hash_table_index];
    // Case: Deleting from head
    if (temp->data == key)
    {
        Node *d_node = temp;
        HT[hash_table_index] = temp->next;
        delete d_node;
    }
    else
    {
        while (temp->next->data != key)
        {
            temp = temp->next;
        }
        Node *d_node = temp->next;
        temp->next = temp->next->next;
        delete d_node;
    }
}

void print(Node* head) {
    Node* temp = head;
    if (head == NULL)
    {
        cout << "-1" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void Hash_Table::print_hash_table() {
    for(int i = 0; i < 10; i++) {
        cout << "index: " << i << endl;
        Node* temp = HT[i];
        print(temp);
    }
}

main()
{
    Hash_Table h1;
    int A[] = {12, 11, 14, 17, 17, 24, 4, 1, 2};
    for (int i = 0; i < 9; i++)
    {
        h1.insert(A[i]);
    }

    cout << "Successfull Search" << endl;
    int key = 1;
    int value = h1.search(key);
    cout << "key :" << key << ", Value :" << value << endl;

    cout << "UNsuccessfull Search" << endl;
    key = 122;
    value = h1.search(key);
    cout << "key :" << key << ", Value :" << value << endl;
    cout << "______________BEFORE DELETION____________\n";
    h1.print_hash_table();
    h1.delete_from_hash_table(2);
    h1.delete_from_hash_table(12);
    cout << "\n______________After DELETION____________\n";
    h1.print_hash_table();
}
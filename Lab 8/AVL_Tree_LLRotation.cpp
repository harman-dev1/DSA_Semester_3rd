#include<iostream>
using namespace std;


class Node {
    public:
    Node* r_child;
    Node* l_child;
    int data;
    int height;
    Node() {
        data = 0;
        height = 0;
        r_child = NULL;
        l_child = NULL;
    }
    Node(int data) {
        this->data = data;
        this->height = 1;
        this->r_child = NULL;
        this->l_child = NULL;
    }
};


class AVL {
    public:
    Node* root;
    AVL() {
        root = NULL;
    }
    Node* insert_node(Node*,int);
    void pre_order_traversal(Node*);
    Node* root_of_AVL();
    int height_of_node(Node*);
    int balance_factor(Node*);
    Node* LL_Rotation(Node*);
};

Node* AVL::LL_Rotation(Node* p) {
    Node* pl = p->l_child;
    Node* plr = pl->r_child;

    pl->r_child = p;
    p->l_child = plr;
    
    p->height = height_of_node(p);
    pl->height = height_of_node(pl);
    
    if(root == p) {
        root = pl;
    }
    return pl;
}

int AVL::balance_factor(Node* root) {
    int l_height;
    int r_height;
    l_height = root && root->l_child? root->l_child->height:0;
    r_height = root && root->r_child? root->r_child->height:0;
    return l_height - r_height;  
}

int AVL::height_of_node(Node* root) {
    int l_height;
    int r_height;
    l_height = root && root->l_child? root->l_child->height:0;
    r_height = root && root->r_child? root->r_child->height:0;
    return max(l_height,r_height)+1;  
}

Node* AVL::insert_node(Node* root,int key) {
    Node* new_node = new Node(key);
    if(root == NULL) {
        root = new_node;
        return root;
    }
    if(key < root->data) {
        root->l_child = insert_node(root->l_child,key);
    }
    else if(key > root->data) {
        root->r_child = insert_node(root->r_child,key);
    }
    root->height = height_of_node(root);
    if(balance_factor(root) == 2 && balance_factor(root->l_child) == 1) {
        return LL_Rotation(root);
    }
    return root;
}

Node* AVL::root_of_AVL() {
    return root;
}

void AVL::pre_order_traversal(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    pre_order_traversal(root->l_child);
    pre_order_traversal(root->r_child);
}

main() {
    AVL a;
    a.root = a.insert_node(a.root,30);
    a.root = a.insert_node(a.root,20);
    a.root = a.insert_node(a.root,25);
    a.root = a.insert_node(a.root,28);
    a.root = a.insert_node(a.root,10);
    a.root = a.insert_node(a.root,15);
    a.root = a.insert_node(a.root,5);
    a.root = a.insert_node(a.root,40);
    a.root = a.insert_node(a.root,50);
    a.root = a.insert_node(a.root,4);
    // a.root = a.insert_node(a.root,0);
    // a.root = a.insert_node(a.root,4);
    // a.root = a.insert_node(a.root,3);
    a.pre_order_traversal(a.root);
}
#include<iostream>
using namespace std;
class Node {
    public:
    int height;
    int data;
    Node* l_child;
    Node* r_child;
    Node() {
        height = 0;
        data = 0;
        l_child = NULL;
        r_child = NULL;
    }
    Node(int data) {
        this->data = data;
        this->height = 1;
        this->l_child = NULL;
        this->r_child = NULL;
    }
};

class AVL {
    public:
    Node* root;
    AVL() {
        root = NULL;
    }
    Node* insert_node(Node*,int);
    Node* delete_node(Node*,int);
    void pre_order(Node*);
    void in_order(Node*);
    void post_order(Node*);
    int height_of_tree(Node*);
    int no_of_nodes(Node*);
    int find_node(Node*,int);
};

Node* AVL::insert_node(Node* root,int key) {
    if(root == NULL) {
        Node* new_node = new Node(key);
        root = new_node;
        return root;
    }
    if(key < root->data) {
        root->l_child = insert_node(root->l_child,key);
    }
    else if(key > root->data) {
        root->r_child = insert_node(root->r_child,key);
    }
    return root;
}

Node* inorder_successor(Node* root) {
    Node* temp = root;
    while(temp && temp->l_child != NULL) {
        temp = temp->l_child;
    }
    return temp;
}

Node* AVL::delete_node(Node* root,int key) {
    if(key > root->data) {
        root->r_child = delete_node(root->r_child,key);
    }
    if(key < root->data) {
        root->r_child = delete_node(root->r_child,key);
    }
    if(key == root->data) {
        if(root->l_child == NULL) {
            Node* temp = root->r_child;
            delete root;
            return temp;
        }
        else if(root->r_child == NULL) {
            Node* temp = root->l_child;
            delete root;
            return temp;
        }
        Node* temp = inorder_successor(root->r_child);
        root->data = temp->data;
        root->r_child = delete_node(root->r_child,temp->data);
    }
    return root;
}

int AVL::find_node(Node* root,int key) {
    if(root == NULL) {
        return 0;
    }
    if(root->data == key) {
        return root->data;
    }
    if(key < root->data) {
        return find_node(root->l_child,key);
    }
    else if(key > root->data) {
        return find_node(root->r_child,key);
    }
}

int AVL::height_of_tree(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int height_of_left_tree = height_of_tree(root->l_child);
    int height_of_right_tree = height_of_tree(root->r_child);
    return (max(height_of_left_tree,height_of_right_tree) + 1); 
}

int AVL::no_of_nodes(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int left_tree_nodes = no_of_nodes(root->l_child);
    int right_tree_nodes = no_of_nodes(root->r_child);
    return left_tree_nodes + right_tree_nodes + 1;
}

void AVL::pre_order(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data <<" ";
    pre_order(root->l_child);
    pre_order(root->r_child);
}

void AVL::in_order(Node* root) {
    if(root == NULL) {
        return;
    }
    in_order(root->l_child);
    cout << root->data <<" ";
    in_order(root->r_child);
}

void AVL::post_order(Node* root) {
    if(root == NULL) {
        return; 
    }
    post_order(root->l_child);
    post_order(root->r_child);
    cout << root->data << " ";
}

main() {
    AVL a;
    a.root = a.insert_node(a.root,10);
    a.root = a.insert_node(a.root,5);
    a.root = a.insert_node(a.root,30);
    a.root = a.insert_node(a.root,40);
    cout << "Before Deletion\n\n";
    cout << "Pre Order :";
    a.pre_order(a.root);
    cout << "\nIn Order :";
    a.in_order(a.root);
    cout << "\nPost Order :";
    a.post_order(a.root);
    cout << "\n" << "Height Of Tree :" << a.height_of_tree(a.root) << "\n";
    cout << "No Of Nodes :" << a.no_of_nodes(a.root) << "\n";
    //cout << "Founded Node :" << a.find_node(a.root,0);
    cout << "After Deletion\n\n";
    a.root = a.delete_node(a.root,30);
    cout << "Pre Order :";
    a.pre_order(a.root);
    cout << "\nIn Order :";
    a.in_order(a.root);
    cout << "\nPost Order :";
    a.post_order(a.root);
}
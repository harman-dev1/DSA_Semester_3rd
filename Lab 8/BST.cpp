#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* r_child;
    Node* l_child;
    Node() {
        data = 0;
        r_child = NULL;
        l_child = NULL;
    }
    Node(int data) {
        this->data = data;
        this->r_child = NULL;
        this->l_child = NULL;
    }
};
class BST {
    Node* root;
    public:
    BST() {
        root = NULL;
    }
    void insert_node(int);
    Node* root_of_BST();
    Node* findNode(int);
    bool is_empty();
    int height_of_BST(Node*);
    void leaf_nodes(Node*);
    int number_of_nodes(Node*);
    void pre_order_traversal (Node*);
    void in_order_traversal (Node *);
    void post_order_traversal (Node*);
    Node* delete_node(Node*,int);
};
void BST::insert_node(int key) {
    Node* new_node = new Node(key);
    if(root == NULL) {
        root = new_node;
        return;
    }
    Node* temp = root;
    Node* temp2;
    while(temp != NULL) {
        temp2 = temp;
        if(key == temp->data) {
            return;
        }
        else if((key) > (temp->data)) {
            temp = temp->r_child;
        }
        else {
            temp = temp->l_child;
        }
    }
    if(key > temp2->data) {
        temp2->r_child = new_node;
    }
    else {
        temp2->l_child = new_node;
    }
}
Node* in_order_succ(Node* root) {
    Node* temp = root;
    while(temp && temp->l_child != NULL) {
        temp = temp->l_child;
    }
    return temp;
}
Node* BST::delete_node(Node* root,int key) {
    if((key) > root->data) {
        root->r_child = delete_node(root->r_child,key);
    }
    if((key) < root->data) {
        root->l_child = delete_node(root->l_child,key);
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
        Node* temp = in_order_succ(root->r_child);
        root->data = temp->data;
        root->r_child = delete_node(root->r_child,temp->data);
    }
    return root;
}
void BST::pre_order_traversal(Node* root) {
    if(root == NULL) {
        return;
    }
    if(root != NULL) {
        cout << root->data << " ";
    }
    if(root->l_child != NULL) {
        pre_order_traversal(root->l_child);
    }
    if(root->r_child != NULL) {
        pre_order_traversal(root->r_child);
    }
}
void BST::post_order_traversal(Node* root) {
    if(root == NULL) {
        return;
    }
    post_order_traversal(root->l_child);
    post_order_traversal(root->r_child);
    cout << root->data << " ";
}
void BST::in_order_traversal(Node* root) {
    if(root == NULL) {
        return;
    }
    in_order_traversal(root->l_child);
    cout << root->data << " "; 
    in_order_traversal(root->r_child);
}
int BST::number_of_nodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int no_of_left_nodes = number_of_nodes(root->l_child);
    int no_of_right_nodes = number_of_nodes(root->r_child);
    return (no_of_left_nodes + no_of_right_nodes + 1);
}
void BST::leaf_nodes(Node* root) {
    if (root == NULL) {
        return;
    }
    if(root->l_child == NULL && root->r_child == NULL) {
        cout << root->data << " ";
    }
    if(root->l_child != NULL) {
        leaf_nodes(root->l_child);
    }
    if(root->r_child != NULL) {
        leaf_nodes(root->r_child);
    }
}
int BST::height_of_BST(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int lheight = height_of_BST(root->l_child);
    int rheight = height_of_BST(root->r_child);
    return (max(lheight,rheight)+1);
}
Node* BST::root_of_BST() {
    if(root == NULL) {
        return root;
    }
    return root;
}

bool BST::is_empty() {
    return root == NULL;
}

Node* BST::findNode(int key) {
    Node* temp = root;
    if(root == NULL) {
        return temp;
    }
    Node* temp2;
    while(temp != NULL) {
        temp2 = temp;
        if(key == temp->data) {
            return temp2;
        }
        else if(key < temp->data) {
            temp = temp->l_child;
        }
        else {
            temp = temp->r_child;
        }
    }
    return temp2;
}
main() {
    BST b;
    b.insert_node(30);
    b.insert_node(15);
    b.insert_node(20);
    b.insert_node(10);
    // cout << b.is_empty() << "\n";
    Node* root = b.root_of_BST();
    cout << "Before Deletion :" ;
    b.in_order_traversal(root);
    root = b.delete_node(root,30);
    cout << "\nAfter Deletion :";
    b.in_order_traversal(root);
    // if(root != NULL) {
    //     cout << root->data << "\n";
    // }
    // else {
    //     cout << root << "\n";
    // }
    // Node* find = b.findNode(40);
    // if(find != NULL){
    //     cout <<"Node "<< find->data << " is Found" << "\n";
    // }
    // else {
    //     cout << find << "\n";
    // }
    //int height = b.height_of_BST(root);
    //cout << height;
    //b.leaf_nodes(root);
    // int nodes = b.number_of_nodes(root);
    // cout << "\n" << nodes << "\n";
    // cout << "Pre Order :";
    // b.pre_order_traversal(root);
    // cout << "\nIn Order Traversal :";
    // b.in_order_traversal(root);
    // cout << "\nPost Order Traversal :";
    // b.post_order_traversal(root);
}
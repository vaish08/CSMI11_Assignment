/*6.Given a BST and two integers (minimum and maximum integers) as parameters, write a program to remove (prune) elements that are not 
within that range*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *right, *left;
};

Node *newNode(int val){
    Node *temp = new Node;
    temp -> data = val;
    temp -> left = temp -> right = NULL;
    return temp;
}

Node *insert(Node* root, int val){
    if(root == NULL){
        return newNode(val);
    }
    if(root -> data > val){
        root -> left = insert(root -> left, val);
    }
    else 
        root -> right = insert(root -> right, val);
    return root; 
}

Node *remove_Nodes(Node *root, int min, int max){
    if(root == NULL) return NULL;

    root -> left = remove_Nodes(root -> left, min, max);
    root -> right = remove_Nodes(root -> right, min, max);

    if(root -> data < min){
        Node *rchild = root -> right;
        delete root;
        return rchild;
    }
    if(root -> data > max){
        Node *lchild = root -> left;
        delete root;
        return lchild;
    }

    return root;
}

void print_nodes(Node *root){
    if(root != NULL){
        print_nodes(root -> left);
        cout << root -> data << " ";
        print_nodes(root -> right);
    }
}

int main(){
    int n, x;
    Node *root = NULL;
    cout << "Enter the  number of nodes: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        root = insert(root, x);
    }
    
    cout << "Inoreder traversal of tree: [before removing]: ";
    print_nodes(root);

    cout << "Enter the range: [min, max] ";
    int min, max;
    cin >> min >> max;

    root = remove_Nodes(root, min, max);

    cout << "Inoreder traversal of tree: [after removing]: ";
    print_nodes(root);
}
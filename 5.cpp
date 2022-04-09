/*5.Write a program to find the following in the binary tree without using recursion:
(i)the number of full nodes ( nodes with two children)
(ii)number of half nodes (nodes with only one child)
(iii)the number of leaf nodes, 
(iv)print all the ancestors of a node 
*/

#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int val;
    Node *left, *right;
};

Node *newNode(int x){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> val = x;
    node -> left = node -> right = NULL;
    return node;
}

Node *insertlevelOrder(int arr[], Node *root, int i, int n){
    if(i < n){
        Node *temp = newNode(arr[i]);
        root = temp;
        root -> left = insertlevelOrder(arr, root -> left, 2*i+1, n);
        root -> right = insertlevelOrder(arr, root -> right, 2*i+2, n);

    }
    return root;
}

void inorder(Node *root){
    if(root != NULL){
        inorder(root -> left);
        cout << root -> val << " ";
        inorder(root -> right);
    }
}

void Nodes_Calc(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int full_nodes = 0, half_nodes = 0, leaf_nodes = 0;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp == NULL){
            if(!q.empty()) q.push(NULL);
            continue;
        }
        if(temp -> left != NULL && temp -> right != NULL) full_nodes++;
        else if(temp -> left == NULL && temp -> right == NULL) leaf_nodes++;
        else half_nodes++;
        if(temp -> left != NULL) q.push(temp -> left);
        if(temp -> right != NULL) q.push(temp -> right);
    }
    cout << full_nodes << " " << leaf_nodes << " " << half_nodes;
}



int main(){
    int n;
    cout << "Enter the number of nodes to be inserted: ";
    cin >> n;
    int a[100005];
    cout << "Enter the values to be entered: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    Node *root = insertlevelOrder(a, root, 0, n);

    Nodes_Calc(root);


}
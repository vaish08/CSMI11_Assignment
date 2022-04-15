/*4.Write a program to Split a Circular doubly Linked List into two equal parts. 
If the number of nodes in the list are odd then make first list one node extra than second list*/
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void insert(Node **head, int val){
    Node *ptr1 = new Node;
    ptr1 -> data = val;
    Node *temp = *head;
    ptr1 -> next = *head;

    if(*head != NULL){
        while(temp -> next != *head){
            temp = temp -> next;
        }
        temp -> next = ptr1;
    }
    else{
        ptr1 -> next = ptr1;
    }
    *head = ptr1;
}

void split(Node *head, Node **head1, Node **head2){
    Node *fast = head;
    Node *slow = head;
    if(head == NULL) return;

    while(fast -> next -> next != head && fast -> next != head){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    if(fast -> next -> next == head) 
        fast = fast -> next;

    *head1 = head;

    if(head -> next != head) 
        *head2 = slow -> next;

    fast -> next = slow -> next;

    slow -> next = head;
}

void print(Node *head){
    Node *temp = head;
    if(head != NULL){
        do{
            cout << temp -> data << " ";
            temp = temp -> next;
        }while(temp != head);
    }
}

int main(){
    int n, x;
    Node *head = NULL, *head1 = NULL, *head2 = NULL;
    cout << "Enter the number of node[inserted at the beginning]: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        insert(&head, x);
    }
    cout << "Before the split: ";
    print(head);

    cout << endl;

    split(head, &head1, &head2);

    cout << "After the splits: ";
    print(head1); cout << "\t";
    print(head2);  

    
}
#include<iostream>
#include<stack>

using namespace std;
class ListNode{

    public: 
        int val;
        ListNode *next;

        ListNode(){
            val = 0;
            next = NULL;
        }

        ListNode(int data){
            this -> val = data;
            this -> next = NULL;
        }
};

class Linkedlist{
    ListNode *head;

    public: 
        Linkedlist() {head = NULL; }

        void insertNode(int);

        void printList();

        void reverse(int);
};

void Linkedlist :: insertNode(int x){
    ListNode *ans = new ListNode(x);
    ListNode *temp = head;
    if(head == NULL){
       head = ans;
       return;
    }
    while(temp -> next != NULL){
       temp = temp -> next;
    }
    temp -> next = ans;
}

void Linkedlist :: printList(){
    ListNode *temp = head;
    while(temp != NULL){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void Linkedlist :: reverse(int d){
   //cout << head -> val << " ";
   ListNode *temp = head, *first = head;
   stack<int> s;
   int cnt = 0;
   while(temp != NULL){
       if(cnt < d){
           s.push(temp -> val);
           cnt++;
           temp = temp -> next;
           continue;
       }
       if(cnt == d){
           cnt = 0;
           while(!s.empty()){
               first -> val = s.top();
               s.pop();
               first = first -> next;
           }
           first = temp;
       }
   }
}





int main(){
    Linkedlist list;

    int n;
    cout << "Enter the number of values to be inserted to linked list: ";
    cin >> n;
    int v[10005];
    cout << "Enter the values: \n"; 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        list.insertNode(v[i]);
    }
    
    cout << "\nThe values present in list are: ";
    list.printList();

    int k;
    cout << "\nReverse blocks of k in a list: ";
    cin >> k;

    list.reverse(k);

    cout << endl;
    list.printList();


}
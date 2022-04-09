#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void interleavequeue(queue <int> q, int n){
    stack<int> s;
    for(int i = 0; i < n/2; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i = 0; i < n/2; i++){
        q.push(q.front());
        q.pop();
    }

    for(int i = 0; i < n/2; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

    cout << "The elements of queue after interleaving the queue: \n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

}

void print_queue(queue <int> q){
     while(!q.empty()){
        cout << q.front() << " ";
    }
}

int main(){
    int n, a[10005];
    queue<int> q;
    cout << "Enter the number of elements to be inserted into queue.";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
       cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        q.push(a[i]);
    }
    //print_queue(q);
    interleavequeue(q, n);
}
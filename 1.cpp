/*1.	Given a queue of integers, rearrange the elements by interleaving the first half of the list with the second half of the list. 
For example, suppose a queue stores the following sequence of values: [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]. Consider the two halves 
of this list: first half: [11, 12, 13, 14, 15] second half: [16, 17, 18, 19, 20]. These are combined in an alternating fashion to form a 
sequence of interleave pairs: the first values from each half (11 and 16), then the second values from each half (12 and 17), then the 
third values from each half (13 and 18), and so on. In each pair, the value from the first half appears before the value from the second half. 
Thus, after the call, the queue stores the following values: [11, 16, 12, 17, 13, 18, 14, 19, 15, 20].*/

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
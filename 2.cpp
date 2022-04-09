#include<iostream>
#include<stack>
using namespace std;
struct Queue{
    stack <int> s1, s2;

    void enqueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue(){
        if(s1.empty()){
            cout << "The queue is empty" << endl;
        }
        int x = s1.top();
        cout << "The element removes is: " << x << endl;
        s1.pop();
    }

    void display(){
        cout << "The values in queue are: ";
        while(!s1.empty()){
            cout << s1.top() << " ";
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        cout << endl;
    }
};

int main(){
    Queue q;
     int x;
    do{
        cout << "Enter the choice: \n 1.Enqueue\n 2.Dequeue \n 3.Display \n";
        int ch;
        cin >> ch;
        if(ch == 1){
            cout << "Enter the number to be added into queue.";
            int x;
            cin >> x;
            q.enqueue(x);
            cout << "The elemented inserted successfully." << endl;
        }
        else if(ch == 2){
            q.dequeue();

        }
        else if(ch == 3){
            q.display();
        }
        else{
            cout << "invalid entry";
        }
        cout << "Do you still want to continue: (1 = Yes / 0 = No)";
        cin >> x;
    }while(x != 0);
    
}
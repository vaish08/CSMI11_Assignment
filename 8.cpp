#include<iostream>

using namespace std;

int n, a[100], k;


void heapify(int i){
    int l = 2*i + 1, r = 2*i+2, m = i;
    if(l < n && a[i] > a[l]) m = l;
    if(r < n && a[m] > a[r]) m = r;
    if(m != i){
        swap(a[m], a[i]);
        heapify(m);
    }
}

int extractMin(){
    if(!n) return -1;
    int m = a[0];
    a[0] = a[n-1];
    n--;
    heapify(0);
    return m;
}

int findkSmallest(){
    for(int i = 1; i < k; i++) extractMin();
    return extractMin();
}

int main(){
    //int n;
    cin >> n;
    //int a[100];
    for(int i = 0; i < n; i++) cin >> a[i];
    //int k;
    cin >> k;

    cout << findkSmallest();
}
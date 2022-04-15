/*7.	Given an array A[] consisting of 0’s, 1’s and 2’s, Write a program to sort this array A[] using Quick Sort*/

#include<iostream>
#include<stdio.h>

using namespace std;

void swap_val(int *a, int *b){
    int *temp = b;
    b = a;
    a = temp;
}

int partition(int a[], int l, int h){
    int i = l-1, pivot = a[h];
    for(int j = l; j < h; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return(i+1);
}

void quick_sort(int a[], int l, int h){
    if(l < h){
        int pi = partition(a, l, h);
        quick_sort(a, l, pi-1);
        quick_sort(a, pi + 1, h);

    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quick_sort(a, 0, n-1);

    cout << "Sorting: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    
}
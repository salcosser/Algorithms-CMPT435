#include <iostream>
#include <string>


void insertion(int arr[] , int n){

    for(int j=2; j<n;j++){
        int key = arr[j];
        int i = j - 1;
        while((i>0)&& /*(arr[i]> key)*/){
            arr[i+1] = arr[i];
            i = i-1;

        }
        arr[i+1] = key;
    }
    return;
}
void change(int a[], int n){
    a[0] = 6;
    return;
}

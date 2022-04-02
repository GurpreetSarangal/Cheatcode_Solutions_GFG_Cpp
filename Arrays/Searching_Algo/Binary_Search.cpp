#include<bits/stdc++.h>
using namespace std;

// complexity O(log n)
int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;
    // int mid = (start + end)/2; // can cause overflow in some cases
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }

        if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main()
{
    int n,key;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[100];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key : ";
    cin>> key;

    int index = binarySearch(arr, n, key);
    if(index>=0){
    cout<<"The key :"<<key<<": appeared at index : "<<index;
    }
    else{
        cout<<"The key :"<<key<<": is absent in the array";
    }

    return 0;
}
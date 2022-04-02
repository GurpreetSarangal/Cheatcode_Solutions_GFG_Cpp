#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void insertionSort(vector<int> &arr, int n){
    
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    vector<int> arr = {14, 10, 9, 7, 6, 1};
    int n=6;
    printArray(arr, n);
    insertionSort(arr, n);
    cout<<"\nSorted array is :"<<endl;
    printArray(arr, n);
    return 0;
}
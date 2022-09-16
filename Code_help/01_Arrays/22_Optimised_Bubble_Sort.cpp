#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void bubbleSortOptimised(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        bool swaped = false;
        for(int j=0; j<n-i-1; j++){
            
            if(arr[j] > arr[j+1]){
                cout<<arr[j]<<" > "<<arr[j+1]<<endl;
                swap(arr[j], arr[j+1]);
                printArray(arr, n);
                swaped = true;
            }
        }
        if(swaped == false)
            break;
    }
}

int main()
{
    vector<int> arr = {14, 10, 9, 7, 6, 1};
    int n=6;
    printArray(arr, n);
    bubbleSortOptimised(arr, n);
    cout<<"\nSorted array is :"<<endl;
    printArray(arr, n);
    return 0;
}
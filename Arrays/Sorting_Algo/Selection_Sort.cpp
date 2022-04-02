#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    for (int i=0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(vector<int> arr, int n){
    for(int i=0;i<n; i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
}

int main()
{
    vector<int> arr={64, 25, 12, 22, 11};
    int n = 5;
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
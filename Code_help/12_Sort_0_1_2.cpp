#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
// sorts an array with 0,1,2 as elements using two pointer approach
void sort012(int arr[], int n){
    int i=0, j=n-1, t=0;
    while(t<=j){
        if(arr[t]==0){
            swap(arr[t], arr[i]);
            i++;
            t++;
        }
        else if(arr[t]==2){
            swap(arr[t], arr[j]);
            j--;
        }
        else if (arr[t]==1){
            t++;
        }
        printArray(arr,n);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[500];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort012(arr, n);
    printArray(arr, n);
    return 0;
}
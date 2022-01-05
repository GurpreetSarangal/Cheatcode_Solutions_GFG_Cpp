#include<bits/stdc++.h>
using namespace std;

void mergeSortedArrays(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    //Copy remaining arrays

    while(i<n){
        arr3[k++] = arr1[i++];
    }
    while(j<n){
        arr3[k++] = arr2[j++];
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
}

int main()
{
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6};
    int arr3[8];

    printArray(arr1, 5);
    printArray(arr2, 3);
    cout<<endl;
    mergeSortedArrays(arr1, 5, arr2, 3, arr3);
    printArray(arr3, 8);
    return 0;
}
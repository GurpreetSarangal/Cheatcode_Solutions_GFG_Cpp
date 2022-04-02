/*
    1,2,3,7,9  --> Sorted
    7,9, 1 ,2,3  --> Sorted and Rotated
        ^ --> Pivot element
*/
#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int> arr, int n){
    int s=0; 
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int main()
{
    vector<int> arr;
    int n,temp;
    cout<<"Enter length of array: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>temp;
        arr.push_back(temp);
    }

    int pivot = getPivot(arr, n);
    cout<<"The pivot element is : "<<arr[pivot];

    return 0;
}
/*sample input

5
7 9 1 2 3
*/
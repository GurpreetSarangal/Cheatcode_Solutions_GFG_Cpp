// Search in a Rotated and Sorted array
// one algorithm can use linear search but it will have O(n) complexity
// but it can be optimised by using binary search O(n) 
#include<bits/stdc++.h>
using namespace std;



int getPivot(vector<int> arr, int n){
    int s=0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0] ){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int> arr, int start, int end, int key){
    int s = start;
    int e = end;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(arr[mid] < key){
            s = mid+1;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else if (arr[mid] == key) {
            return mid;
        }
        mid = s + (e-s)/2;
    }
}

// uses binary search in one of the two parts 
int findPosition(vector<int> arr, int n, int k){
    int pivot = getPivot(arr, n);
    
    if(k>=arr[pivot] && k<=arr[n-1]){
        // BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else{
        // BS on first line
        return binarySearch(arr, 0, pivot, k);
    }
}

int main()
{
    vector<int> arr;
    int n,key, temp;
    cout<<"Enter the length: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<"Element to search: ";
    cin>>key;

    int index = findPosition(arr, n, key);
    cout<<"The element '"<<key<<"' is at index : "<<index;
    return 0;
}
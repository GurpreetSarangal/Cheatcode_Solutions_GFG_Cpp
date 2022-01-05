// First and Last position of an element in Sorted Array
#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e =mid-1;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int lastOcc(int arr[], int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s =mid+1;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(int arr[], int n, int key){
    int a = firstOcc(arr, n, key);
    int b = lastOcc(arr, n, key);
    return pair<int, int>(a,b);
}
int main()
{
    int arr[] = {1,2,3,3,5};
    pair<int , int> ans = firstAndLastPosition(arr, 5, 3);
    cout<<" "<< ans.first<<endl
        <<ans.second;
    
    return 0;
}
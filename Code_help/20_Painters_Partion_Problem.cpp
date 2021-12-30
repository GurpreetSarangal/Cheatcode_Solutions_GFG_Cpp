#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int k, int mid){
    int painters = 1;
    int boards = 0;
    for(int i = 0; i<n; i++){
        if(boards + arr[i] <= mid){
            boards += arr[i];
        }
        else{
            painters ++;
            if(painters > k || arr[i] > mid){
                return false;
            }
            boards = arr[i];
        }
    }
    return true;
}

int partitionBoard(vector<int> arr, int n, int k){
    int ans = -1;
    int s = 0;

    int sum =0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(arr, n, k, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {5,5,5,5};
    int k =2;
    int n = 4;
    cout<<"ans : "<< partitionBoard(arr, n, k);
    return 0;
}
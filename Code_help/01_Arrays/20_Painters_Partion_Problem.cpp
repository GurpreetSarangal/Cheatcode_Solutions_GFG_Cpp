#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int k, int mid){
    int painters = 1;
    int boards = 0;
    for(int i = 0; i<n; i++){
        if(boards + arr[i] <= mid){ // check before allocating 
            boards += arr[i]; // allocate only if possible 
        }
        else{// if not possible
            painters ++; // increase count of painters
            if(painters > k || arr[i] > mid)// and return false if number of painters exceeds k or current element is greater that mid itself 
            {
                return false;
            }
            boards = arr[i];// if everything is ok then allocate the current number of boards to next painter
        }
    }
    return true;
}

// allocates number of boards between k painters to paint all boards in minimum time
int partitionBoard(vector<int> arr, int n, int k){
    int ans = -1;
    // search space is 0 ---------- sum of all elements
    int s = 0;

    int sum =0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(arr, n, k, mid)){
            ans = mid;// save the possible ans and
            e = mid - 1; // move to the right of the search space
        }
        else{// in case of no solution
            s = mid + 1; // move to the left of the search space
        }
        mid = s + (e-s)/2;// update mid
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
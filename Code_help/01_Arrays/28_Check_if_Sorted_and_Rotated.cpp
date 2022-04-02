// check if the array is sorted and rotated or not
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> arr){
    int count = 0;
    int n = arr.size();
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }
    if( arr[0] < arr[n-1])
        count++;
    
    return count<=1;
}

int main()
{
    vector<int> arr = {4,5,1,2,3};

    cout<<"this is "<<check(arr);

    return 0;
}
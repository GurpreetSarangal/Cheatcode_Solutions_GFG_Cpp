#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int k){

    vector<int> temp(arr.size());

    for(int i=0; i<arr.size(); i++){
        temp[ (i+k) % arr.size()] = arr[i];
    }

    arr = temp;
}

void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<"  ";
    }cout<<endl;
}

int main()
{
    vector<int> arr = {-1, -100, 3, 99};

    printArray(arr);
    rotate(arr, 3);
    printArray(arr);
    return 0;
}
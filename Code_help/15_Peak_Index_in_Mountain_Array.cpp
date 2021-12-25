#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int peakIndexInMountainArray (vector<int> &arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s + (e - s)/2;
    // this condition becomes false when s = e ie. only single element is left which is the peak
    while(s<e)
    {
        if(arr[mid] < arr[mid+1]){
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
    vector<int> arr = {3,4,5,1};
    int index_of_peak = peakIndexInMountainArray(arr);
    cout<<"The peak in vector : ";
    printArray(arr);
    cout<<"is : "<<arr[index_of_peak]<<endl;
    return 0;
}
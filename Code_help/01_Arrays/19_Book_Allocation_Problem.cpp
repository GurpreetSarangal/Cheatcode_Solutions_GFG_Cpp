/*
Given an array of integers which represents teh number of pages in the 'i th' book.
There are 'm' number of students and the task is to allocate all the books to their students is such a way that :
1. Each student gets atlest one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguouss manner.

*** Books should be allocated to 'm' students such that the MAXIMUM number of pages assigned to a student is MINIMUM. ***

example :
    arr = {10, 20, 30, 40}

        10 | 20 30 40  => 10 , 90 => 90 =
        10 20 | 30 40  => 30 , 70 => 70  ==> 60
        10 20 30 | 40  => 60 , 40 => 60 =
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = 0;
            pageSum = arr[i];
        }
    }
    return true;
}

// returns the minimum of the  maximum number of pages allocated to students 
int allocateBooks(vector<int> arr, int n, int m){
    int s = 0;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e - s)/2;

    while(s<=e){
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n=4;
    int m=2;
    int min_of_maxes = allocateBooks(arr, n, m);
    cout<<"the minimum of maximum number of pages allocated to a student is: "<<min_of_maxes;
    
    return 0;
}
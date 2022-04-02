/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
example:
    n = 6
    arr[]= {7, 10, 4, 3, 20, 15}
    K = 3

    output: 7
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // int partition(int arr[], int low, int high){
    //     int pivot = arr[low];
    //     int i = low + 1;

    //     for(int j=low + 1; j>=high; j++){
    //         if(arr[j] < pivot  ){
    //             if(j != i){
    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //             }
    //             i++;
    //         }
    //     }
    //     arr[low] = arr[i-1];
    //     arr[i-1] = pivot;

    //     return i - 1; 
    // }

    // int kthSmallest(int arr[], int p, int q , int k)
    //     {
    //         // cout<<"p = "<<p<<"q = "<<q;
    //         if(p == q){
    //            if(p == k-1){
    //                return arr[p];
    //            }
    //         //   else
    //         //     return -1;
    //         }
    //         else{
    //             int r=partition(arr, p, q);
    //             if(r==k-1){
    //                 // display(arr, p, q);
    //                 // cout<<"\nr = "<<r;
    //                 return arr[r];
                    
    //             }
    //             else if(r<k-1)
    //                 return kthSmallest(arr, r+1, q, k);
    //             else
    //                 return kthSmallest(arr, p, r-1, k);
    //         }
    //     }
        // even the above code didn't work
        // btw it's quicksort's algo partition




    //     void merge(int array[], int const left, int const mid, int const right)
    // {
    //     auto const subArrayOne = mid - left + 1;
    //     auto const subArrayTwo = right - mid;
     
    //     // Create temp arrays
    //     auto *leftArray = new int[subArrayOne],
    //          *rightArray = new int[subArrayTwo];
     
    //     // Copy data to temp arrays leftArray[] and rightArray[]
    //     for (auto i = 0; i < subArrayOne; i++)
    //         leftArray[i] = array[left + i];
    //     for (auto j = 0; j < subArrayTwo; j++)
    //         rightArray[j] = array[mid + 1 + j];
     
    //     auto indexOfSubArrayOne = 0, 
    //         indexOfSubArrayTwo = 0; 
    //     int indexOfMergedArray = left; 
     
    //     while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    //         if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
    //             array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    //             indexOfSubArrayOne++;
    //         }
    //         else {
    //             array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    //             indexOfSubArrayTwo++;
    //         }
    //         indexOfMergedArray++;
    //     }
    //     while (indexOfSubArrayOne < subArrayOne) {
    //         array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    //         indexOfSubArrayOne++;
    //         indexOfMergedArray++;
    //     }
    //     while (indexOfSubArrayTwo < subArrayTwo) {
    //         array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    //         indexOfSubArrayTwo++;
    //         indexOfMergedArray++;
    //     }
    // }
     
    
    // void mergeSort(int array[], int const begin, int const end)
    // {
    //     if (begin >= end)
    //         return; // Base Condition
     
    //     auto mid = begin + (end - begin) / 2;
    //     mergeSort(array, begin, mid);
    //     mergeSort(array, mid + 1, end);
    //     merge(array, begin, mid, end);
    // }
    //  I used bubble sort but it lead to time limit excedence error

    //     void bubbleSort(int arr[], int l, int r){
    //     int n = r - l + 1;
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j< n-i-1; j++){
    //             if(arr[j] > arr[j+1])
    //             {
    //                 int temp;
    //                 temp = arr[j];
    //                 arr[j] = arr[j+1];
    //                 arr[j+1] = temp;
    //             //     cout<<temp<<"  ";
    //             //     display(arr, n);
    //             }
                
    //         }
    //     }
        
    // }

// void display(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<"  ";
//     }
//     cout<<endl;
// }

// int kthSmallest(int arr[], int l, int r, int k)
//     {
//         // first sorting the array
//         int n = r - l+1;
//         // display(arr, n);
//         mergeSort(arr, l, r);
//         // cout<<endl;
//         // display(arr, n);
//         return arr[k-1];
//     }












    // int randomPartition(int arr[], int l, int r); 
    
    // This function returns k'th smallest element in arr[l..r] using 
    // QuickSort based method. ASSUMPTION: ELEMENTS IN ARR[] ARE DISTINCT 
    int kthSmallest(int arr[], int l, int r, int k) 
    { 
        // If k is smaller than number of elements in array 
        if (k > 0 && k <= r - l + 1) 
        { 
            // Partition the array around a random element and 
            // get position of pivot element in sorted array 
            int pos = randomPartition(arr, l, r); 
    
            // If position is same as k 
            if (pos-l == k-1) 
                return arr[pos]; 
            if (pos-l > k-1) // If position is more, recur for left subarray 
                return kthSmallest(arr, l, pos-1, k); 
    
            // Else recur for right subarray 
            return kthSmallest(arr, pos+1, r, k-pos+l-1); 
        } 
    
        // If k is more than the number of elements in the array 
        return INT_MAX; 
    } 
    // this function swaps the two numbers provided
    void swap(int *a, int *b) 
    { 
        int temp = *a; 
        *a = *b; 
        *b = temp; 
    } 
    
    // Standard partition process of QuickSort(). It considers the last 
    // element as pivot and moves all smaller element to left of it and 
    // greater elements to right. This function is used by randomPartition() 
    int partition(int arr[], int l, int r) 
    { 
        int x = arr[r], i = l; 
        for (int j = l; j <= r - 1; j++) 
        { 
            if (arr[j] <= x) 
            { 
                swap(&arr[i], &arr[j]); 
                i++; 
            } 
        } 
        swap(&arr[i], &arr[r]); 
        return i; 
    } 
    
    // Picks a random pivot element between l and r and partitions 
    // arr[l..r] around the randomly picked element using partition() 
    int randomPartition(int arr[], int l, int r) 
    { 
        int n = r-l+1; 
        int pivot = rand() % n; 
        swap(&arr[l + pivot], &arr[r]); 
        return partition(arr, l, r); 
    } 
        
};

int main() 
{ 
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    Solution s; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
    cout << "K'th smallest element is " << s.kthSmallest(arr, 0, n-1, k); 
    return 0; 
}
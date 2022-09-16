// Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 
// Input:
// N = 5, D = 2
// arr[] = {1,2,3,4,5}
// Output: 3 4 5 1 2
// Explanation: 1 2 3 4 5  when rotated
// by 2 elements, it becomes 3 4 5 1 2.

// There can be three ways 
// Method 1:
// using temp array -> 
// 1. store the first d elements in a temp array
// 2. shift the rest of the array[]
// 3. store back the d elements
// Time complexity: O(n)    space complexity: O(d)

// Method 2:
// Rotate one by one 
// its function will be
// void leftRotatebyOne(int arr[], int n)
// {
//     int temp = arr[0], i;
//     for (i = 0; i < n - 1; i++)
//         arr[i] = arr[i + 1];
 
//     arr[n-1] = temp;
// }
// time complexity: O(n*d)      space complexity: O(1)

// Method: 3
// A Juggling Algorithm
// This is an extension of method 2. Instead of moving one by one, divie the array in different sets where numer of sets is equal to GCD of n and d and move the elements within sets.
// If GCD is 1 as is for the abobe example array(n=7 and d=2), the elements will be moved within arr[l+d] to arr[l] and finally store temp at teh right place
// time complexity: O(n)       space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;

int gcd (int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}
void leftRotate(int arr[], int d, int n){
    d = d%n;
    int GCD = gcd(d, n);
    for(int i=0; i<GCD; i++){
        int temp = arr[i];
        int j =i;
        while (1){
            int k = j+d;
            if(k >= n)
                k = k-n;
            
            if(k == i)
                break;
            
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function calling
    leftRotate(arr, 2, n);
    printArray(arr, n);
 
    return 0;
}
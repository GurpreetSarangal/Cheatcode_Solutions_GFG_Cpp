/*
Given an array arr[] containing N integers. In one step, any element of the array can either be increased or decreased by one. Find minimum steps required such that the product of the array elements becomes 1.

 

Example 1:

Input:
N = 3
arr[] = {-2, 4, 0}
Output:
5
Explanation:
We can change -2 to -1, 0 to -1 and 4 to 1.
So, a total of 5 steps are required
to update the elements such that
the product of the final array is 1. 
Example 2:
Input:
N = 3
arr[] = {-1, 1, -1} 
Output :
0
Explanation:
Product of the array is already 1.
So, we don't need to change anything.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function makeProductOne() which takes an integer N and an array arr of size N as input and returns the minimum steps required.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 10^5
-10^3 ≤ arr[i] ≤ 10^3
*/
#include<bits/stdc++.h>
using namespace std;

int MinStep(int a[], int n)
{
    // To store the count of 0s, positive
    // and negative numbers
    int positive = 0,
        negative = 0,
        zero = 0;
    
    // To store the number of steps
    int step = 0;
    for(int i=0; i<n; i++){
        // If array element is equal to 0
        if(a[i] == 0){
            zero++;
        }

        // If array element is a negative number
        else if(a[i] < 0)
        {
            negative++;

            // Extra steps needed to make it -1
            step = step + (-1 - a[i]);
        }

        // If array element is a positive number
        else{
            positive++;
            // This statement gives us extra steps needed to make it 1
            step = step + (a[i] - 1);
        }
    }

    // At this point array will have only -1s, 0s and 1s
    if(negative % 2 == 0){
        // as 
        step += zero;
    }
    else{
        if(zero>0){
            step += zero; 
        }
        else{
            step += 2;
        }
    }
}

int main()
{
    int a[] = {3,2,5,-2,5,-2};
    int n = sizeof(a)/sizeof(a[0]);
    cout<< MinStep(a, n);

    return 0;
}
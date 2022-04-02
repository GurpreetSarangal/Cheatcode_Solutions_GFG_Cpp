/*
For an integer N find the number of trailing zeroes in N!.

Example 1:

Input:
N = 5
Output:
1
Explanation:
5! = 120 so the number of trailing zero is 1.
*/
#include<bits/stdc++.h>
using namespace std;

int findTrailingZeroes(int n){
    
    if(n<0)// Negative numbers edge case
        return -1;
    
    int count =0;

    //keep dividing n by powers of 5 and update count
    for(int i=5; n/i >= 1; i*=5){
        count += n/i;
        //Trailing 0s in n! = Count of 5s in prime factors of n!
        //                  = floor(n/5) + floor(n/25) + floor(n/125) + ....

    }
    return count;
}
int main()
{
    int n = 100;
    cout<<"count of trailing 0s in "<< n << "! is "
        <<findTrailingZeroes(n);
        
    return 0;
}
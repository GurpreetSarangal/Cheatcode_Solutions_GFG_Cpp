/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
Example 2:

Input:
N = 10
A[] = {1,2,3,4,5,6,7,8,10}
Output: 9

Your Task :
You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  parameters and returns the value of the missing number.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 10^6
1 ≤ A[i] ≤ 10^6
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MissingNumber_MY_WAY(vector<int> &array, int n)
    {
        // using technique of the summation formula
        int sum_all = 0;
        for (int num = 0; num <= n; num++)
        {
            sum_all += num;
        }
        for (int ele : array)
        {
            sum_all -= ele;
        }
        return sum_all;
    }
    int MissingNumber_XOR(vector<int> array, int n)
    {
        int a = array[0];
        int b =1;
        for(int i=1; i<n; i++){
            a = a ^ array[i];
        }
        for(int i=2; i<=n+1; i++){
            b = b ^ i;
        }

        return (a^b);
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << "Input N: ";
        int n;
        cin >> n;
        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i)
        {
            cout << "Input " << i << " th element : ";
            cin >> array[i];
        }
        Solution obj;
        cout << obj.MissingNumber_XOR(array, n) << "\n";
    }
    return 0;
}
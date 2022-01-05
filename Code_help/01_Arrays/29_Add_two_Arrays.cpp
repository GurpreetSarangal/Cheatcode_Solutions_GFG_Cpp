/*
    1 2 3 4
   +      6
    1 2 4 0
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> arr){
    int s=0;
    int e=arr.size() - 1;
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
    return arr;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m){
    int i = n-1;
    int j = m-1;

    vector<int> ans;
    int carry = 0;

    while(i>=0 && j>=0){
        int val1 = a[i];
        int val2 = b[j];

        int sum = val2 + val1 + carry;
        carry = sum/10;
        sum = sum %10;
        ans.push_back(sum);
        i--; j--;
    }

    while(i>=0){
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0){
        int sum = a[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }

    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }cout<<endl;
}
int main()
{
    vector<int> arr1 = {9,9};
    vector<int> arr2 = {1};
    vector<int> ans = findArraySum(arr1, arr1.size(), arr2, arr2.size());
    cout<< "    ";
    printArray(arr1);
    cout<< "   +";
    printArray(arr2);
    cout<<"--------------------\n    ";
    printArray(ans);
    return 0;
}
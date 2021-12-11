#include<bits/stdc++.h>
using namespace std;
// retrns 
bool isPowerOfTwo(int n){
    int ans = 1;
    for(int i=0; i<=30; i++){
        if(ans == n){
            return true;
        }
        if(ans < INT_MAX/2)
            ans=ans*2;
    }
    return false;
}

int main()
{
    int num;
    cin>>num;
    cout<<isPowerOfTwo(num);
    return 0;
}
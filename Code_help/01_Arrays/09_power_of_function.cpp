#include<bits/stdc++.h>
using namespace std;
int power(int a, int b){
    int ans = 1;
    for (int i=1; i<=b; i++){
        ans = ans * i;
    }
    return ans;
}
int main()
{
    int a, b;
    cin>>a>>b;
    int pow = power(a,b);
    cout<<pow;
    return 0;
}
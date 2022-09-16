#include<bits/stdc++.h>
using namespace std;

int get_approx_root(int n){
    int i;
    for(i=1; i*i<=n; i++){
        continue;
    }
    return i-1;
}

int main()
{
    int n;
    cin>>n;
    int root = get_approx_root(n);
    cout<<"integral part of root is :"<<root;
    return 0;
}
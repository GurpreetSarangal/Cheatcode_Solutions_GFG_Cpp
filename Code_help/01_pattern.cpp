#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row = 1, col, n, i=1;
    cout<<"number of lines: ";
    cin>>n;
    
    while(row<=n){
        col=1;
        i=1;
        while(i<=n-row){
            cout<<"  ";
            i++;
        }
        
        while(col <= row){
            cout<<col<<" ";
            col++;
        }
        col=col-2;
        while(col>=1){
            cout<<col<<" ";
            col--;
        }
        cout<<'\n';
        row++;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row=1, col,i;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    while(row<=n){
        col=1;
        i=row;
        while(col<=n-row+1){
            cout<<col<<' ';
            col++;
        }
        while(i-1>0){
            cout<<"* ";
            i--;
        }
        while(i<row){
            cout<<"* ";
            i++;
        }
        col--;
        while(col>=1){
            cout<<col<<" ";
            col--;
        }
        cout<<"\n";
        row++;
    }
    return 0;
}
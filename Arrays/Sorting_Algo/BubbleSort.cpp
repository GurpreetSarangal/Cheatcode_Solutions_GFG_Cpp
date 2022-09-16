#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-i-1; j++){
            if(a[j]>a[j+1]){
                temp = a[i];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
    int a[20], n, i;
    cout<<"Enter number of element a["<<i<<"] = ";
    cin >> n;
    for(i=0; i<n; i++){
        cout<< a[i]<<"  ";
    }cout<<endl;
    return 0;
}
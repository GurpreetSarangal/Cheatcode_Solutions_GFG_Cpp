#include<bits/stdc++.h>
using namespace std;

vector<int> reverse_whole_array(vector<int> arr){
    int s = 0;
    int e = arr.size()-1;

    while(s<=e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return arr;
}

vector<int> reverse_after_m(vector<int> arr, int m){
    int s = m + 1; // start from the index
    int e = arr.size()-1;

    while(s<=e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return arr;
}

void printArray(vector<int> arr){
    for(int i:arr){
        cout<< i <<"  ";
    }cout<<endl;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    printArray(arr);
    arr = reverse_whole_array(arr);
    printArray(arr);
    arr = reverse_whole_array(arr);
    arr = reverse_after_m(arr, 3);
    printArray(arr);

    return 0;
}
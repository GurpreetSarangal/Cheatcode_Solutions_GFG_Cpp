#include<bits/stdc++.h>
using namespace std;

int index_of_max_of_array(int arr[], int n){
    int max = INT_MIN;
    int index=0;
    for(int i=0; i<n; i++){
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }
    cout<<max<<endl;
    return index;
}

char max_Occuring_Character(string str){
    int arr[26] = {0};
    int index;
    for(int i=0; i<str.length();i++){
        if(str[i] > 'a' && str[i] <'z'){
            index = str[i] - 'a';
            arr[index]++;
        }
        if(str[i] > 'A' && str[i] <'Z'){
            index = str[i] - 'A';
            arr[index]++;
        }
    }
    // cout<<index_of_max_of_array(arr, 26)<<endl;
    // cout<<index_of_max_of_array(arr, 26) + 'a'<<endl;
    return char(index_of_max_of_array(arr, 26) + 'a');
}

int main()
{
    string s = "any string here";
    cout<<max_Occuring_Character(s);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void printArray(vector<char> chars){
    for(char ch : chars){
        cout<<ch;
    }cout<<endl;
}

int compress(vector<char> &chars){
    int i=0;
    int ansIndex=0;
    int n = chars.size();

    while(i<n){
        int j = i+1;
        while(j<n && chars[i] == chars[j]){
            j++;
        }
        chars[ansIndex++] = chars[i];
        
        int count = j-i;
        if(count > 1){
            string cnt = to_string(count);
            for(char ch:cnt){
                chars[ansIndex++] = ch;
            }
        }
        // cout<<"char -> "<<chars[i]<<" count -> "<<count<<endl;
        i=j;
    }
    return ansIndex;
}

int main()
{
    vector<char> ch = {'a','a','a','b','b','b','b','c','c','c','c','c','d'};
    printArray(ch);
    int length = compress(ch);
    printArray(ch);
    cout<<length;
    return 0;
}
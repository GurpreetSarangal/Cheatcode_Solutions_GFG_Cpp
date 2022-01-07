#include<bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26] , int b[26]){
    for(int i=0; i<26; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

void printArray(int arr[]){
    for(int i=0; i<26; i++){
        cout<<char('a'+i)<<"->"<<arr[i]<<" ";
    }cout<<endl;
}

bool checkInclusion(string s1, string s2){
    int count1[26] = {0};
    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int i=0; 
    int windowSize = s1.length();
    int count2[26] = {0};

    while(i<windowSize && i<s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    // cout<<"f array -> ";
    // printArray(count1);
    // cout<<"S array -> ";
    // printArray(count2);
    if(checkEqual(count1, count2))
        return 1;
    while(i< s2.length()){
        // cout<<"i -> "<<i<<endl;

        char newChar = s2[i];
        int index = newChar - 'a';
        // cout<<"newChar -> "<<newChar<<endl;
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        // cout<<"oldChar -> "<<oldChar<<endl;
        count2[index]--;

        i++;
        // cout<<"S array -> ";
        // printArray(count2);
        if(checkEqual(count1, count2))
            return 1;
    }
    return 0;
}

int main()
{
    string s1="ab";
    string s2="eidbaooo";

    cout<<checkInclusion(s1, s2);
    return 0;
}
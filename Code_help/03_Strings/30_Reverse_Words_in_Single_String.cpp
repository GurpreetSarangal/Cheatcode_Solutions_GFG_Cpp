#include<bits/stdc++.h>
using namespace std;

void reverse_word(string &str, int s, int e){
    while(s<=e){
        swap(str[s++], str[e--]);
    }
}

void reverse_all_words(string &str){

    int s = 0;
    int e = 0;
    for(int i=0; i <= str.length(); i++){
        if(str[i] == ' ' || str[i] == '\0'){
            e = i-1;
            reverse_word(str, s, e);
            s = i+1;
        }
    }

}

int main()
{
    string s = "this is a multiword string";
    reverse_all_words(s);
    cout<<s;
    return 0;
}
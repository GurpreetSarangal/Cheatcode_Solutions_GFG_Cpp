#include<bits/stdc++.h>
using namespace std;

string removeOccuring(string s, string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    return 0;
}
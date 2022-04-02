#include<bits/stdc++.h>
using namespace std;

// simple case sensitive palindrome check
bool check_Palindrome(string str){
    
    int s= 0;
    int e= str.length() - 1;

    while(s<=e){
        if(str[s] != str[e]){
            return 0;
        }
        s++; e--;
    }
    return 1;
}

// converts Alphabets to lower case
char toLower(char ch){
    if(ch > 'a' && ch < 'z'){
        return ch;
    }
    else if(ch>'A' && ch<'Z'){
        return char(ch - 'A' + 'a');
    }
}

// checks that character is a valid alphanumric character
bool isValid(char ch){
    if(ch > 'a' && ch < 'z'){
        return 1;
    }
    else if(ch>'A' && ch<'Z'){
        return 1;
    }
    else if(ch>'0' && ch<'9'){
        return 1;
    }
    else 
        return 0;
}

// special function to check palidrome only by considering alphanumeric characters
bool case_insensitive_palindrome_check(string str){
    int s=0;
    int e=str.length()-1;

    while(s<=e){
        
        if(!isValid(str[s])) // skip the character if not a valid one
            s++;
        if(!isValid(str[e]))
            e--;
        
        if(isValid(str[s])  &&  isValid(str[e]) ){// check only if it is valid
            if(tolower(str[s]) != tolower(str[e]))
                return 0; // false if both are not same
            s++; e--;
        }
        
    }
    return 1;// reaches here only if word is a palidrome
}

int main() 
{
    string str = "g#$@#@@$$^&*(^u@$@@#$@r@#$@p&%*^p#$@ru$@@#$@#$@g";
    string str2 = "A man, A plan, A canal: Panama";
    cout<<case_insensitive_palindrome_check(str);
    return 0;
}
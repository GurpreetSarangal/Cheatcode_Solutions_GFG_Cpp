#include<bits/stdc++.h>
using namespace std;
// returns true if number is power of two 
bool isPowerOfTwo(int n){
    int ans = 1;
    for(int i=0; i<=30; i++){
        if(ans == n){
            return true;
        }
        if(ans < INT_MAX/2)
            ans=ans*2;
    }
    return false;
}

//using bit manipulation on the number
bool optimisedIsPowerOfTwo(int n){
    int number_of_set_bits=0,current_bit;
    while(n!=0 && number_of_set_bits<=1){
        current_bit=n&1;
        if(current_bit == 1){
            number_of_set_bits++;
        }
        n=n>>1;
    }

    if(n==0 && number_of_set_bits==1){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int num;
    cout<<"Enter a number:: ";
    cin>>num;
    if(isPowerOfTwo(num)){
        cout<<num<<" can be represented as 2^x";
    }
    else{
        cout<<num<<" can not be represented as 2^x";
    }
    return 0;
}
// Euclid's Algo
// gcd(a,b) = gcd(a-b,b)
//            gcd(a%b,b)

// relation between lcm and gcd
// lcm(a,b)*gcd(a,b) = a*b;


#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    
    if(b == 0)
        return a;
    
    while(a != b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

int main()
{
    
    return 0;
}
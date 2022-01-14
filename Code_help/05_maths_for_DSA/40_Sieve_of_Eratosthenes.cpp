// find the number of prime numbers in range 0 to n
// brute force approach:
// pick every number and check if it is prime or not. O(n^2)  --> TLE

// Sieve of Eratosthenes
// example n = 40
// 1. Firstly mark every number as prime number
// 2. Then keep moving and mark false for the number which are in the table of a prime number

// complexity --> O(n*log(log n))

#include<bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
int countPrimes(int n){
    int cnt = 0;
    vector<bool> prime(n+1, true);// creates an array with n+1 true elements
    prime[0] = prime[1] = false;// because 0 and 1 are not prime

    for(int i = 2; i<n; i++){
        if(prime[i]){
            cnt++;// increase the count of primes

            for(int j=2*i; j<n; j++){
                prime[j] = 0; // mark false to every number which appear in i 's table
            }
        }
    }
    return cnt;
}

int main()
{
    
    return 0;
}
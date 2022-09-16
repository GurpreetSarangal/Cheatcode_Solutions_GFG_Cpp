#include<bits/stdc++.h>
using namespace std;
void printArray();
void boolprint(vector<bool>);
vector<long long> prime;
void sieve(int n){
    vector<bool> isPrime(n+1, true);
    for(long long i=2; i<=n; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(long long j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void segmentSieve(int l, int h){
    long long sq = floor(sqrt(h));
    sieve(sq);
    printArray();
    vector<bool> isPrime(h-l+1, true);
    boolprint(isPrime);
    for(long long p: prime){
        long long sm = (l/p)*p;
        cout<<"sm = "<<sm<<endl;
        cout<<"p = "<<p<<endl;
        if(sm < l)
            sm += p;
        for(long long m = sm*2; m<=h; m+=p){
            isPrime[m-l] = false;
        }
        boolprint(isPrime);
    }
    printArray();
    cout<<"The prime numbers between "<<l<<" and "<<h<<" are:\n";
    for(long long i=l; i<=h; i++){
        if(isPrime[i-l] == true)
            cout<<i<<"  ";
    }cout<<endl;
}

void printArray(){
    for(long long i:prime){
        cout<<i<<"  ";
    }cout<<endl;
}

void boolprint(vector<bool> arr){
    for(int i =0; i<arr.size(); i++){
        cout<<i+1<<"->"<<arr[i]<<"  ";
    }cout<<endl;
}
int main()
{
    int l, h;
    cout<<"Enter lower and upper limits: \n";
    cin>>l>>h;
    printArray();
    segmentSieve(l,h);
    return 0;
}
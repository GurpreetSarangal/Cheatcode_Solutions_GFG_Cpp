#include<bits/stdc++.h>
#include<math.h>
using namespace std;
void printx(int a){
    cout<< a <<"  ";
}

int main()
{
    int n,i=31;
    bool bit,c=1;
    int bin[32]={0};
    unsigned long int sum=0;
    cout<<"Enter a number: ";
    cin>>n;

    while(i>=0){
        bit = n&1;
        bin[i]=bit;
        i--;
        n=n>>1;
        // the commented code didn't worked because the int variable cannot hold a 32 bit binary number 
        // cout<<"bit before adding: "<<bit<<"   ";
        // bit = !bit;
        // bit = bit + c;
        // cout<<"bit after adding : "<<int(bit)<<"   ";
        // if(bit == 0 && c==true){
        //     c=true;
        //     cout<<"c is true"<<"   ";
        // }
        // else{
        //     c=false;
        //     cout<<"c is false"<<"   ";
        // }
        // cout<<"sum before: "<<sum<<"   " ;
        // sum = (bit*pow(10,i)) + sum;
        // cout<<"sum : "<<sum<<"   ";
        // i--;
        // n=n>>1;
        // cout<<"i : "<<i<<"   "<<"n : "<<n<<endl;
    }
    cout<<endl;
    for_each (bin,bin+32,printx);
    return 0;
}
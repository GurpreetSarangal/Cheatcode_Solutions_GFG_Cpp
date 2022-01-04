#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(8);

    cout<<"Finding 6-> "<<binary_search(v.begin(), v.end(), 6)<<endl;
    cout<<"finding -6 -> "<<binary_search(v.begin(), v.end(), -6)<<endl;

    cout<<"Lower Bound -> "<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<"Upper Bound -> "<<upper_bound(v.begin(), v.end(), 6) - v.begin()<<endl;

    int a=3;
    int b=5;

    cout<<"max -> "<<max(a,b)<<endl;
    cout<<"min -> "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a -> "<<a<<endl<<"b -> "<<b<<endl;
    
    string abcd = "abcd" ;
    reverse(abcd.begin(), abcd.end());
    cout<<"String -> "<<abcd<<endl;

    rotate(v.begin(),v.begin() + 1, v.end());
    cout<<"After Rotate: "<<endl;
    for(int i:v){
        cout<<i<<"  ";
    }cout<<endl;

    sort(v.begin(), v.end());
    for(int i:v){
        cout<<i<<"  ";
    }cout<<endl;

    return 0;
}
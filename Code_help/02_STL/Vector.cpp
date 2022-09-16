#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    vector<int> a(5,1);
    vector<int> a2(a);

    cout<<"Print a2: "<<endl;
    for(int i:a2){
        cout<<i<<"  ";
    }cout<<endl;

    cout<<"Capacity-> "<<v.capacity()<<endl;
    // return the number of elements which can be stored in it not the no. element current in vector
    
    v.push_back(1);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    // Capacity of vector gets doubled every time it is overflowed

    cout<<"Size-> "<<v.size()<<endl;
    // returns no. of elements currently in vector

    cout<<"Element at 2nd Index-> "<<v.at(2)<<endl;

    cout<<"Front "<<v.front()<<endl;
    cout<<"Back "<<v.back()<<endl;

    cout<<"Before pop: "<<endl;
    for(int i:v){
        cout<<i<<"  ";
    }cout<<endl;

    v.pop_back();

    cout<<"After pop: "<<endl;
    for(int i:v){
        cout<<i<<"  ";
    }cout<<endl;

    cout<<"Before clear size: "<<v.size()<<endl;
    v.clear();
    cout<<"After clear size: "<<v.size()<<endl;

    cout<<"After clear capacity: "<<v.capacity()<<endl;

    // v.begin(), v.end()
    // iterators
    return 0;
}
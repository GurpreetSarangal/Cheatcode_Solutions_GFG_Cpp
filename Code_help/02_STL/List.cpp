#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    list<int> l2 (5, 100);
    list<int> l3 (l2);

    for(int i:l3){
        cout<<i<<"  ";
    }cout<<endl;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    for(int i:l){
        cout<<i<<"  ";
    }cout<<endl;

    cout<<"size of list "<<l.size()<<endl;
    return 0;
}
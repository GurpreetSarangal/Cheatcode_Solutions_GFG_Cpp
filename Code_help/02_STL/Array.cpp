#include<iostream>
#include<array>
using namespace std;

int main()
{
    int basic[3]= {1,2,3};
    array<int, 3> arr = {3,2,1};
    int size = arr.size();
    for (int i:arr){
        cout<<i<<"  ";
    }cout<<endl;

    cout<<"Element at 2 Index: "<< arr.at(2)<<endl
        <<"Empty or not: "<<arr.empty()<<endl;
    
    cout<<"First Element-> "<<arr.front()<<endl;
    cout<<"Last Element-> "<<arr.back()<<endl;

    return 0;
}
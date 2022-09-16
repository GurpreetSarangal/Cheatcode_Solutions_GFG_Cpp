#include<iostream>
#include<map>
using namespace std;

int main(){

    map<int, string> m;

    m[1] = "Gurpreet";
    m[2] = "Sarangal";
    m[3] = "BCA";

    m.insert({5, "Bheem"});

    cout<<"Before erase: "<<endl;
    for (auto i: m){
        cout<<i.first<<"  "<<i.second<<endl;
    }cout<<endl;

    cout<<"Finding 3-> "<<m.count(3)<<endl;
    cout<<"Finding -13-> "<<m.count(-13)<<endl;

    m.erase(5);
    cout<<"After erase: "<<endl;
    for(auto i:m ){
        cout<<i.first<<"  "<<i.second<<endl;
    }cout<<endl<<endl;

    auto it = m.find(3);

    for(auto i = it; i != m.end(); i++){
        cout<<(*i).first<<"  "<<(*i).second<<endl;
    }cout<<endl<<endl;

    return 0;
}
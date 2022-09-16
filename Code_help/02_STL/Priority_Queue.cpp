#include<iostream>
#include<queue>
using namespace std;

int main(){
    // max heap
    priority_queue<int> max_heap;

    //min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    max_heap.push(1);
    max_heap.push(3);
    max_heap.push(2);
    max_heap.push(0);

    cout<<"Size -> "<<max_heap.size()<<endl;

    int n = max_heap.size();
    for (int i = 0; i < n; i++)
    {
        cout<<max_heap.top()<<"  ";
        max_heap.pop();
    }cout<<endl;

    min_heap.push(5);
    min_heap.push(1);
    min_heap.push(2);
    min_heap.push(4);
    min_heap.push(0);
    
    int m = min_heap.size();
    for (int i = 0; i < m; i++)
    {
        cout<<min_heap.top()<<"  ";
        min_heap.pop();
    }cout<<endl;

    cout<<"Empty or not : "<<min_heap.empty()<<endl;
    
}
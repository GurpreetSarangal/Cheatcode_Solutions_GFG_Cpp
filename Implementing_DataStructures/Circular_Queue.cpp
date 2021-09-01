/*
    In the previous program (Queue.cpp) of simple queue suppose that after inserting or deleting elements from the queue, the  queue with three elements look like as shown
         0   1   2  3   4   5
        ----------------------
        \  \  \  \ 40\ 25\ 50\
        ----------------------
    Now, if we want to insert a new element into the queue having value of rear=5, then we cannot insert a new element although there is lot of space available in the queue. The solution to this problem is a circular queue is which new element can be added to the beginning of the queue and rear will be pointing to the same.
    Thus in a circular queue, we keep on inserting elements without need to worry about rubbing out of space unless the array implementing queue is full, which represents overflow condition.
    
 */
#include<bits/stdc++.h>
using namespace std;
#define SIZE 6

class circular_Queue{
    int elem[SIZE];
    int front, rear;
    public:
        circular_Queue(){   front=rear=-1;  }
        void insert(int);
        void remove();
        void display();
        ~circular_Queue(){  cout<<"Destroying CIRCULAR Queue: ";}
};

void circular_Queue::insert(int item){
    if( (rear == (SIZE - 1)   &&  front==0) || (front == rear+1) )
        cout<<"OVERFLOW QUEUE IS FULL:";
    else if(rear == -1){
        front=rear=0; 
        elem[rear]=item;
    }
    else if(rear==(SIZE-1) ){
        rear =0;
        elem[rear] = item;
    }
    else {
        rear++;
        elem[rear] = item;
    }
}

void circular_Queue::remove(){
    if(front == -1){
        cout<<"UNDERFLOW: QUEUE IS EMPTY/n";
    }
    else if(rear == front)
        rear = front=-1;
    else if(rear == (SIZE-1))
        front=0;
    else
        front++;
}

void circular_Queue::display(){
    int i;
    if(rear >= front){
        for(i=front; i<=rear; i++){
            cout<<elem[i]<<'\t';
        }
    }
    else{
        for(i=front; i<=(SIZE-1); i++){
            cout<<elem[i]<<'\t';
        }
        for(i=0; i<=rear; i++){
            cout<<elem[i]<<'\t';
        }
    }
}
int main()
{
    circular_Queue Q;
    int choice, val;
    return 0;
}
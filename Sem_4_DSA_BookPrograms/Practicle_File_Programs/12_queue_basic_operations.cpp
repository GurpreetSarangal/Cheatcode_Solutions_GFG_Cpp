#include<bits/stdc++.h>
using namespace std;

class Queue{
    int arr[100];
    int front, rear;
    public:
        Queue(){
            front = 0;
            rear = -1;
        }
        void enqueue(int);
        int dequeue();
        int front_peek();
        int rear_peek();
        void traverse();
};

int main()
{
    Queue Q;
    int len, input;
    cout<<"Enter number of elements: ";
    cin>>len;

    while(len > 0){
        cout<<"enter an element to push: ";
        cin>>input;
        Q.enqueue(input);
        len--;
    }

    cout<<"Queue before dequeue operation:: "<<endl;
    Q.traverse();

    int removed = Q.dequeue();

    cout<<"Queue after dequeue operation:: "<<endl;
    Q.traverse();
    return 0;
}

void Queue::enqueue(int element){
    if( rear>= 99){
        cout<<"Overflow"<<endl;
        return;
    }

    arr[++rear] = element;
}

int Queue::dequeue(){
    if( rear < 0){
        cout<<"Underflow"<<endl;
        return -1;
    }

    int removed = arr[front];
    front++;
    if(rear < front){
        front = 0;
        rear = -1;
    }
    return removed;
}

int Queue::front_peek(){
    return arr[front];
}

int Queue::rear_peek(){
    return arr[rear];
}

void Queue::traverse(){
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
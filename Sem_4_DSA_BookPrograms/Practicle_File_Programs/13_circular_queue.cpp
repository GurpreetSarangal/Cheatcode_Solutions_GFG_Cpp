#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    int arr[10];
    int front, rear, max_size;
    public:
        CircularQueue(){
            front = 0; 
            rear = -1;
            max_size = 10;
        }
        void enqueue(int);
        int dequeue();
        void traverse();
};

int main()
{
    CircularQueue Q;
    int len, input;
    cout<<"Enter number of elements: ";
    cin>>len;

    while(len > 0){
        cout<<"enter an element: ";
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

void CircularQueue::enqueue(int element){
    if( (front==0 && rear == max_size-1) || (rear != -1 && front == rear+1)){
        cout<<"Overflow!!"<<endl;
        return;
    }
    
    
    rear = (rear + 1)%(max_size); 

    arr[rear] = element;
}

int CircularQueue::dequeue(){
    if (rear==-1){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int removed = arr[front];

    front = (front+1) % (max_size);
    return removed;
}

void CircularQueue::traverse(){
    if(rear >= front){
        for(int i=front; i<=rear; i++){
            cout<<arr[i] <<"   ";
        }
        cout<<endl;
    }
    else{
        for(int i=front; i<max_size; i++){
            cout<<arr[i]<<"   ";
        }
        for(int i=0; i<=rear; i++){
            cout<<arr[i]<<"   ";
        }
        cout<<endl;
    }
}
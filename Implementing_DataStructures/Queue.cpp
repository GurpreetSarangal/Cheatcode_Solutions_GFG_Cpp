/*
 * A Queue is a data structure in which elements are added at one end and deleted from the other end. 
 * The end where elements are added to is known as REAR and the end where the elements are deleted from queue is know as FRONT. We should use queue data strcture when we want to model First In First Out behaviour. 
 * Queues are basically of two types:
 * 1. Simple Queue
 * 2. Circular Queue
 

 this is the implementation of simple Queue data structure
 */
#include<bits/stdc++.h>
using namespace std;
#define SIZE 6

class My_queue
{
    int elem[SIZE];
    int front, rear;
    public:
        My_queue(){    front=rear= -1;     }
        void insert(int);
        void remove();
        void display();
        ~My_queue(){   cout<<"Destroying simple queue"; }
};

void My_queue::insert(int item){
    if(rear == (SIZE-1))
        cout<<"overflow Queue is full";
    else if(rear == -1)
        front = rear = 0;
    else if(rear < (SIZE - 1))
        rear++;
    elem[rear] = item;
}

void My_queue::remove(){
    if((front > 0) && (front < SIZE)){
        cout<<"\nElement removed = "<<elem[front];
        front++;
    }
    else
        cout<<"underflow: Queue is empty";
}

void My_queue::display(){
    for(int i=front; i<=rear; i++){
        cout<<elem[i]<<'\t';
    }
}

int main()
{
    My_queue Q;
    int choice, val;
    char ch;
    while(1){
        cout<<"\nChoice 1.Insert\t 2.Remove\t 3.Display\t 4.Exit: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter element to push: ";
            cin >> val;
            Q.insert(val);
            break;
        case 2: 
            Q.remove();
            break;
        case 3: 
            Q.display();
        case 4:
            exit(0);
        
        default:
            cout<<"Wrong INPUT !!";
            break;
        }
    }
    return 0;
}
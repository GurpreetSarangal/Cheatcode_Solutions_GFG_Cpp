/*
    * A My_stack data structure allows the elements to be added or removed only at one end known as the top of the My_stack.
    * My_stack models the real life Last In First Out [LIFO] behaviour.
    * The most commonly used operations on the My_stack are Push and Pop. 
    * The Push operation add a new element onto the top of a My_stack and pop operation removes the topmost element from a My_stack. 
*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 6
class My_stack{
    private:
        int elem[MAX];
        int top;
    public:
        My_stack(){ top=-1; }
        void push(int);
        void pop();
        void display();
        ~My_stack(){   cout<<"\nDestroying My_stack\n";   }
};

void My_stack:: push(int item){
    if(top = (MAX - 1)){
        cout<<"\noverflow: My_stack is full\n";
    }
    else{
        top++;
        elem[top] = item;
    }
}

void My_stack::pop(){
    if(top ==  -1){
        cout<<"\nUnderflow: Stack Empty\n";
    }
    else{
        cout<<"\nElement popped = "<<elem[top]<<endl;
        top--;
    }
}

void My_stack:: display(){
    cout<<"\n contents of stack: \n";
    for(int i=0; i<=top; i++)
        cout<<elem[i]<<'\t';

}
int main()
{
    My_stack s;
    int choice, val;
    char ch;
    while(1){
        cout<<"\nChoice 1. Push\t 2. Pop\t 3. Display\t 4. Exit"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1: 
            cout<<"\nEnter element to push: ";
            cin>>val;
            s.push(val);
            break;
        case 2: s.pop();
        case 3: s.display();
        case 4: exit(-1);
        default:cout<<"Wrong INPUT/n";
            break;
        }
    }
    return 0;
}
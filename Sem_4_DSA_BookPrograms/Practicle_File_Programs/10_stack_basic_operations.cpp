#include<bits/stdc++.h>
using namespace std;

class Stack{
    int arr[100];
    int top;
    public:
        Stack(){
            top = -1;
        }
        void push(int element);
        int peek();
        int pop();
        void traverse();
};

int main()
{
    Stack st;
    int len, input;
    cout<<"enter number of elements in stack : ";
    cin>>len;
    while(len > 0){
        cout<<"enter an element to push: ";
        cin>>input;
        st.push(input);
        len--;
    }

    cout<<"Stack before pop operation:: "<<endl;
    st.traverse();

    int removed = st.pop();

    cout<<"Stack after pop operation:: "<<endl;
    st.traverse();
    return 0;
}

void Stack::push(int element){
    if(top >= 99){
        cout<<"overflow!!"<<endl;
        return;
    }
    top++;
    arr[top] = element;
}

int Stack::peek(){
    if(top < 0){
        cout<<"underflow!!"<<endl;
        return -1;
    }
    return arr[top];
}

int Stack::pop(){
    if(top < 0){
        cout<<"underflow!!"<<endl;
        return -1;
    }
    int removed = arr[top];
    top--;
    return removed;
}

void Stack::traverse(){
    for(int i=0; i<=top; i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

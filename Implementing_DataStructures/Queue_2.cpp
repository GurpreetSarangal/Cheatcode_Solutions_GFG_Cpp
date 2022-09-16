#include<bits/stdc++.h>

using namespace std;
#define MAXSIZE 5
class Queue
{
    string q[MAXSIZE];
    int front, rear;
    public:
    Queue()
    {
        front =0;
        rear=-1;
    }
    void enqueue(string);
    string dequeue();
    void display();
    bool isEmpty();

    ~Queue()
    {
        cout<<"Destroying Queue";
    }
   
};

void Queue :: enqueue(string item)
{
    if(rear==(MAXSIZE-1))
    cout<<"Overflow : Queue Full";
    else
    {
        rear++;
        q[rear]=item;
    }
}

bool Queue :: isEmpty()
{
    return (rear==-1);
}

string Queue :: dequeue()
{
    string item;
    item = q[front];
    if(front<rear)
    front ++;
    else
    {
        front =0; rear =-1;
    }
    return(item);
}

void Queue :: display()
{
    // cout<<"rear = "<<rear<<endl
    //     <<"front = "<<front<<endl; 
    for(int i=front;i<=rear;i++)
    {
        cout<<q[i]<<'\t';
    }
        cout<<endl;
}

int main()
{
  Queue q1;
  int choice;
  string val;
  string item;
  char ch;
  cout<<"PRogram started";
  while(1)
  {
      cout<<"\n Choice 1.. Enqueue \t 2.Dequeue \t 3.Display \t 4.Exit  -> ";
      cin>>choice;

      switch(choice)
      {
        case 1: cout<<"Enter Element to insert  ";
                cin>>val;
                q1.enqueue(val);
                break;
      
        case 2: 
                
      
                if(q1.isEmpty()==true)
                cout<<"Underflow:queue Empty";
                else
                {
                item=q1.dequeue();
                cout<<"Element removed "<<item;
                } 
                break;
    
        case 3: q1.display();
                break;
     
        case 4: exit(0);     
      }
  }
}
#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node* link;
};

class linkedList{
    private:
        node* head;
        int length;
    public:
        linkedList(){
            head = NULL;
            length = 0;
        }
        node* create();
        void traverse();
        node* search(int);
        ~linkedList();
};

int main()
{
    linkedList list;
    list.create();
    list.traverse();
    int item;
    cout<<"Enter item to search: ";
    cin>>item;
    node* loc = list.search(item);
    if(loc == NULL){
        cout<<"Item not found"<<endl;
    }
    else{
        cout<< loc->info <<" found!!"<<endl;
    }
    return 0;
}

node* linkedList::create(){
    node *ptr;
    char ch='Y';
    while(ch=='y' || ch=='Y'){
        if(head==NULL){
            head = new node;
            ptr = head;
        }
        else{
            ptr->link = new node;
            ptr =  ptr->link;
        }
        int data;
        cout<<"Info : ";
        cin>>data;
        ptr->info = data;
        cout<<"New Node?? (Y/N): ";
        cin>>ch;
    }
    ptr->link = NULL;
    return head;
}

void linkedList::traverse(){
    node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->info<<"  ";
        ptr = ptr->link;
    }
    cout<<endl;
}

node* linkedList::search(int item){
    node *ptr = head;
    while(ptr != NULL){
        if(ptr->info == item){
            return ptr;
        }
        ptr = ptr->link;
    }
    return NULL;
}

linkedList::~linkedList(){
    cout<<"Self Distruction Mode ON"<<endl;
    node* ptr = head;
    while(ptr!=NULL){
        node *next = ptr->link;
        delete ptr;
        ptr = next;
    }
}
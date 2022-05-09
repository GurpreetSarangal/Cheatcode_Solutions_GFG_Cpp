#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node* link;
};

class linkedList{
    private:
        node* head;
    public:
        linkedList(){
            head = NULL;
        }
        void create();
        void traverse();
        void delete_node(int);
        node *get_prev_loc(int);
        ~linkedList();
};

int main()
{
    linkedList list;
    list.create();
    cout<<"Before deleting: "<<endl;
    list.traverse();

    int index;
    cout<<"enter index to delete: ";
    cin>>index;
    list.delete_node(index);
    cout<<"After deleting"<<endl;
    list.traverse();
    return 0;
}

node* linkedList::get_prev_loc(int index){
    node* ptr = head;
    for(int i=0; i<index-1; i++){
        if(ptr == NULL){
            return NULL;
        }
        ptr = ptr->link;
    }
    return ptr;
}

void linkedList::delete_node(int index){
    node *prev = get_prev_loc(index);
    if(prev == NULL){
        cout<<"wrong index"<<endl;
        
    }
    else if(prev == head){
        if(prev->link == NULL){
            head = NULL;
        }
        else{ 
            head = prev->link;
        }
        delete prev;
    }
    else{
        node *del = prev->link;
        node *next = del->link;
        prev->link = next;
        delete del;
    }
}

void linkedList::create(){
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
}

void linkedList::traverse(){
    node *ptr = head;
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(ptr != NULL){
        cout<<ptr->info<<"  ";
        ptr = ptr->link;
    }
    cout<<endl;
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
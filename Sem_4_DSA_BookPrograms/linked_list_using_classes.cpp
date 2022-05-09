#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node *link;
};

class linkedList
{
private:
    node *head;
    int length;
public:
    linkedList();
    void create();
    void traverse();
    void deleteNode(int);
    node* search(int);
    void insert_at_location(int, node*);
    ~linkedList();
};

linkedList::linkedList()
{
    head = NULL;
    length = 0;
}

void linkedList::create(){
    node* ptr;
    char ch = 'y';
    while(ch=='Y' || ch=='y'){
        if(head == NULL){
            head = new node;
            ptr = head;
        }
        else{
            ptr->link = new node;
            ptr = ptr->link;
        }
        int info;
        cout<<"Enter the info: ";
        cin>>info;
        ptr->info = info;
        length ++;
        cout<<"Do you want to add new node(Y/N): ";
        cin>>ch;
    }
}
void linkedList::traverse(){
    node* ptr=head;
    while(ptr != NULL){
        cout<<ptr->info<<"  ";
        ptr = ptr->link;
    }
    cout<<endl;
}

void linkedList::deleteNode(int item){
    node *ptr=head, *prev=NULL;
    while(ptr != NULL){

        if(ptr->info == item){
            if(prev == NULL){
                head = ptr->link;
                delete ptr;
            }
            else{
                prev->link = ptr->link;
                delete ptr;
            }
            length --;
            return;
        }
        prev = ptr;
        ptr = ptr->link;
    }
}

linkedList::~linkedList()
{
    node *ptr=head;
    cout<<"deleting the nodes"<<endl;
    while(ptr != NULL){
        node *next = ptr->link;
        delete ptr;
        length --;
        ptr = next;
    }
}

node* linkedList::search(int item){
    node *loc, *ptr;
    
    ptr = head;
    while( ptr!= NULL && ptr->info != item){
        ptr = ptr->link;
    }
    if ( ptr != NULL && ptr->info == item){
        return ptr;
    }
    return NULL;
}

// void linkedList::insert_at_location(int item, int loc){
//     if (loc < 0 || loc>=length){
//         cout<<"index not valid"<<endl;
//         return;
//     }
//     node* ptr = head;
//     node* new_ = new node;
//     new_->info = item;
//     if (loc == 0){ // insert at starting
//         new_->link = head;
//         head = new_;
//     }
//     else{
//         while(ptr != NULL){

//         }
//     }
// }

void linkedList::insert_at_location(int item, node* loc){
    node* newNode;
    newNode = new node;
    newNode->info = item;
    if(loc==NULL){
        cout<<"inserting at the front as loc=NULL"<<endl;
        newNode->link = head;
        head = newNode;
    }
    else{
        newNode->link = loc->link;
        loc->link = newNode;
    }
}

int main()
{
    linkedList list;
    list.create();
    list.traverse();
    list.deleteNode(10);
    list.traverse();

    node* loc = list.search(20);
    cout<<loc->info<<" - "<<loc<<endl;
    return 0;
}
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
        linkedList();
        void create();
        void traverse();
        void insert(int,int);
        node* get_loc(int);
        ~linkedList();
};



int main()
{
    linkedList list;
    list.create();
    cout<<"List Before Insertion: "  <<endl;
    list.traverse();

    int element, at_index;
    cout<<"Enter element to be inserted: ";
    cin>>element;
    cout<<"Enter the index of new element: ";
    cin>>at_index;
    list.insert(element, at_index);

    cout<<"List after Insertion: "<<endl;
    list.traverse();
    return 0;
}


linkedList::linkedList(){
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
        length++;
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

node* linkedList::get_loc(int index){
    node *ptr = head;
    int i=0;
    if(index > length || index == 0){
        return NULL;
    }
    while(ptr != NULL){
        if (i==index){
            return ptr;
        }
        i++;
        ptr = ptr->link;
    }

}

void linkedList::insert(int element, int index){
    node *loc = get_loc(index-1);
    node* newNode = new node;
    newNode->info = element;
    if(loc==NULL){
        newNode->link = head;
        head = newNode;
    }
    else{
        newNode->link = loc->link;
        loc->link = newNode;
    }
}
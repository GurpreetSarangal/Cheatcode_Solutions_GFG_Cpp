#include<bits/stdc++.h>
using namespace std;
/* To implement a linked list which is a collection of nodes of same type, we use ~self referential~ structures which is a structure having a reference to itself. */
// This dectaration of structure node consists of two members, the first one is the information part and the other one is self referential pointer member which points to the next node of the list.
struct node
{
    int info;
    node* next;
};
/* A linked list is a dynamic data structure which grows and shrinks in size when the elements are inserted or removed. In other words, memory is allocated or deallocated only when the elements are inserted or removed. */ 
class linked_list{
    node* start;
    public:
        linked_list(){  start=NULL; }
        void create();
        void display();
        ~linked_list();
};

int main(){
    linked_list list;
    list.create();
    list.display();
    return 0;
}

/* A linked list is a linear collection of elements called nodes, where each node consists of two parts info and a pointer pointing to the next node. The nodes of the linked list are normally not stored in contiguous memory locations. */
void linked_list::create(){
    node* ptr;
    char ch='y';
    int x;
    while(ch == 'y'){
        ptr = new node;
        cout<<"enter info. part of new node = ";
        cin>>x;
        ptr->info = x;
        ptr->next = start;
        start=ptr;
        cout.flush();
        cout<<"\nWant to input more:[y/n]  ";
        cin>>ch;
    }
}
/* Each linked list contains a pointer variable start which contains the address of the first node in the list. The last node of the list contains the null value in the pointer field which represents end of the linked list. */
void linked_list::display(){
    node *ptr = start;
    while(ptr != NULL){
        cout<<ptr->info<<'\t';
        ptr = ptr->next;
    }
}

linked_list::~linked_list(){
    node *ptr=start;
    cout<<"destroying... linked list\n";
    while(ptr != NULL){
        ptr = ptr->next;
        delete start;
        start = ptr;
    }
}
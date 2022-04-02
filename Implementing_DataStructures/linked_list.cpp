// program to implement singly linked lists along with following operations on it
// 1-> traverse
// 2-> create node
// 3-> delete node
// 4-> search node
// 5-> insert a new node at location given



#include<iostream>
#include<bits/stdc++.h>
#define NULL 0
using namespace std;
struct node{
    int roll_No;
    string name="" ;
    node *link;
};

class linklist{
    private:
        node *head;
    public:
        linklist(){
            head = NULL;
        }
        void create();
        void traverse();
        void instloc(int, string, node *);
        void deleteitem(int);
        node *search(int);
        ~linklist();
};

int menu(){
    cout<<"\n main menu\n"
        <<"1. traverse linked list\n"
        <<"2. Insert a node after node with giver rollno\n"
        <<"3. delete a node with given item\n"
        <<"   Any other number: EXIT\n\t";
    int choice;
    cin>>choice;
    return choice;
}

int main(){
    linklist lily;
    lily.create();
    int choice;
    char ch;string name="";
    do{
        choice = menu();
        switch(choice){
            case 1: lily.traverse();
                    break;
            case 2: 
                    int item;
                    cout<<"Enter item(rollno) to search from list: ";
                    cin>>item;
                    node *loc = lily.search(item);
                    int roll;
                    
                    cout<<"\n Enter rollno and name to be inserted into new nade(student) :\n"
                        <<"Roll No: ";
                    cin>>roll;
                    cout<<"Name: ";
                    getline(cin, name);// to input spaces as character
                    lily.instloc(roll, name, loc);
                    break;
            case 3: 
                    cout<<"\n Enter rollno part of node{student) to be deleted";
                    cin>>roll;
                    lily.deleteitem(roll);
                    break;
            default:
                    cout<<"\n End of Operation";
        }
        cout<<"\n Want to continue\n";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    cout<<"---- End of Program ----";
    return 0;
}
// Accept a item(roll_No) to search for and return the location of node whose roll_No part equal to item
node* linklist::search(int item){
    node *loc, *ptr;
    loc == NULL;
    ptr = head;
    while((ptr != (NULL) ) && (item != ptr->roll_No) ){
        ptr = ptr->link;// go to next node
    }
    if(item == ptr -> roll_No)
        loc == ptr;
    return(loc);
}

// insert a new node (student) after the node pointed to by 'loc' or insert at the front if loc = NULL
void linklist::instloc(int roll, string new_Name, node *loc){
    node *newnode;
    newnode = new node;
    newnode->roll_No = roll;
    newnode->name = new_Name;
    if(loc == NULL){
        cout<<"inserting at the front as loc = NULL\n";
        newnode->link = head;
        head = newnode;
    }
    else{
        newnode->link = loc->link;
        loc->link = newnode;
    }
    
}

// creates new linked list
void linklist::create(){
    node* ptr;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        if(head == NULL){
            head = new node;
            ptr = head;
        }
        else{
            ptr->link = new node;
            ptr = ptr->link;
        }
        int roll; string new_name;
        cout<<"\n Enter RollNo and name of new node \t";
        cin >>roll;
        getline(cin, new_name);
        ptr->roll_No = roll;
        ptr->name = new_name;
        cout<<"do you want to continue: [Y/N] ";
        cin >> ch;
    }
    ptr->link = NULL;
}
// prints data of all nodes
void linklist::traverse(){
    node* ptr = head;
    cout<<"\nRoll No and Name of students are\n";
    while(ptr != NULL){
        cout<<ptr->roll_No<<'\t'<<ptr->name<<'\n';
        ptr = ptr->link;
    }
}

void linklist::deleteitem(int roll){
    node *ptr, *prevloc, *loc;
    ptr = head;// ptr points to first node
    prevloc = NULL;
    while((ptr != NULL) && (roll != ptr->roll_No)){
        prevloc = ptr;
        ptr = ptr ->link;
    }
    if(roll == ptr->roll_No){
        loc = ptr;
    }
    else{
        cout<<"roll no not found exit without deletion\n";
        return;
    }
    if(prevloc == NULL){
        head = head->link;
    }
    else{
        prevloc->link = loc->link;
    }

    delete loc;
}

linklist::~linklist(){
    node *ptr = head;
    cout<<"destroying ... linklist\n";
    while(ptr!=NULL){
        ptr = ptr->link;
        delete head;
        head = ptr;
    }
}

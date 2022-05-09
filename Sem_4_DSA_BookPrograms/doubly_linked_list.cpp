#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *plink;
    node *flink;
};

class LinkedList
{
private:
    node *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    void create();
    void traverse_forward();
    void traverse_backward();
    ~LinkedList();
};

void LinkedList::create()
{
    node *ptr;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        if (head == NULL)
        {
            head = new node;
            head->plink = NULL;
            ptr = head;
        }
        else{
            ptr->flink = new node;
            (ptr->flink)->plink = ptr;
            ptr = ptr->flink;
        }
        int data;
        cout<<"Enter the info part of new node: ";
        cin>>data;
        ptr->info = data;
        cout.flush();
        cout<<"Do you want to continue(Y/n) : ";
        cin>>ch;
    }
    ptr->flink = NULL;
    tail = ptr;
}

int main()
{

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left, * right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void pre_order(Node* root);

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    pre_order(root);
    cout<<endl;
    return 0;
}

void pre_order(Node* root){
    if(root!= NULL){
        cout<<"  "<<root->data;
        pre_order(root->left);
        pre_order(root->right);
    }
}
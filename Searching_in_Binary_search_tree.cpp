#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *Creating_Node()
{
    Node *ptr = new (Node);
    cout << "Enter the data" << endl;
    int value;
    cin >> value;
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int Binary_search(Node* root, int key){
    if(root == NULL){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    else if(root->data>key){
        return Binary_search(root->left, key);
    }
    else if(root->data<key){
        return Binary_search(root->right, key);
    }
}


int main(){

    Node *root = new (Node);
    Node *second = new (Node);
    Node *third = new (Node);
    Node *fourth = new (Node);
    Node *fifth = new (Node);
    Node *sixth = new (Node);
    root = Creating_Node();
    second = Creating_Node();
    third = Creating_Node();
    fourth = Creating_Node();
    fifth = Creating_Node();
    sixth = Creating_Node();

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    third->left = sixth;

    cout<<"Enter the key"<<endl;
    int key;
    cin>>key;
    if(Binary_search(root, key)){
        cout<<"Key is found"<<endl;
    }
    else{
        cout<<"Key is not found"<<endl;
    }

    

    return 0;
}
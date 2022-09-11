#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* Enqueue(Node* Tail, Node* Head){
    Node* node = new (Node);
    if(node == NULL){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        cout<<"Enter the elelment"<<endl;
        cin>>node->data;
        node->next = NULL;
        if(Head == NULL){
            Head = Tail = node;
            return Tail;
        }
        else{
            Tail->next = node;
            Tail = node;
            return Tail;
        }
    }
}
Node* Dequeue(Node* Head){
    if(Head == NULL){
        cout<<"Queue Underflow"<<endl;
        return NULL;
    }
    else{
        Node* ptr = new (Node);
        ptr = Head;
        Head = Head->next;
        delete ptr;
        return Head;
    }
    
}

void Traversal(Node* Head){
    Node* ptr = new (Node);
    ptr = Head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    Node* Head = NULL;
    Node* Tail = NULL;

    int choice;
    while (1)
    {
        cout << "Enter the choice\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Tail = Enqueue(Tail, Head);
            if(Head == NULL){
                Head = Tail;
            }
            continue;
        case 2:
            Head = Dequeue(Head);
            continue;
        case 3:
            Traversal(Head);
            continue;
        default:
            if (choice != 4)
                cout << "Invalid Input";
            return 0;
        }
    }
}
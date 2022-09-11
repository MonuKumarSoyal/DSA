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

void PreOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
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
    int choice;
    bool loop_terminator = true;

    while (loop_terminator)
    {
        cout << "Enter the choice\n1. PreOrder\n2. InOrder\n3. PostOrder\n4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            PreOrder(root);
            cout << endl;
            break;
        case 2:
            InOrder(root);
            cout << endl;
            break;
        case 3:
            PostOrder(root);
            cout << endl;
            break;
        default:
            if (choice != 4)
            {
                cout << "Invalid Input" << endl;
            }
            loop_terminator = false;
        }
    }

    return 0;
}
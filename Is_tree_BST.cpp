#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *ptr = new (Node);

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

int IsBST(Node *root)
{
    static int temp;
    static int count;

    // if(first_data == 0){
    //     root_data = root->data;
    //     first_data++;
    // }
    if (root != NULL)
    {
        IsBST(root->left);
        if (count != 0)
        {
            if (temp >= root->data)
            {
                return 0;
            }
        }
        temp = root->data;
        if (count == 0)
        {
            count++;
        }
        IsBST(root->right);
    }

    else
    {
        return 1;
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

    if (IsBST(root))
    {
        cout << "Tree is BST" << endl;
    }
    else
    {
        cout << "Tree is not BST" << endl;
    }

    return 0;
}
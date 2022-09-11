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
Node *Creating_One_More_Node(int value)
{
    Node *temp = new (Node);
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int Insertion(Node *root, int value)
{
    Node *ptr = new (Node);
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            cout << "value cannot be inserted" << endl;
            return 0;
        }

        else if (ptr->data > value)
        {
            if (ptr->left == NULL)
            {
                ptr->left = Creating_One_More_Node(value);
                return 1;
            }
            else
            {
                ptr = ptr->left;
            }
        }

        else
        {
            if (ptr->right == NULL)
            {
                ptr->right = Creating_One_More_Node(value);
                return 1;
            }
            else
            {
                ptr = ptr->right;
            }
        }
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

    InOrder(root);
    cout << endl;
    cout << "Enter the key" << endl;
    int key;
    cin >> key;
    Insertion(root, key);
  
    InOrder(root);

    return 0;
}
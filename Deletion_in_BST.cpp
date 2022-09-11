#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int number = 0;

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

Node* Binary_search(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data>key){
        return Binary_search(root->left, key);
    }
    else if(root->data<key){
        return Binary_search(root->right, key);
    }
}

int Deletion(Node *root, int key){
    Node *ptr = new (Node);
    ptr = root;

    if(number == 0){
        ptr = Binary_search(root, key);
        number++;
    }
    

    if(ptr->left == NULL && ptr->right == NULL){
        ptr = NULL;
        delete(ptr);
        return 1;
    }
    else if(ptr->left != NULL){
        ptr->data = ptr->left->data;
        Deletion(ptr->left, ptr->data);
    }
    else if(ptr->right != NULL){
        ptr->data = ptr->right->data;
        Deletion(ptr->right, ptr->data);
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
    
    Deletion(root, key);

    InOrder(root);

    return 0;
}
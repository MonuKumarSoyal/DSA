#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int isFull(Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

Node *push(Node *Top)
{
    cout << "-----------------------------------\n";
    Node *ptr = new (Node);
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
        return Top;
    }
    else
    {
        cout << "Enter the data" << endl;
        int value;
        cin >> value;
        ptr->data = value;
        ptr->next = Top;
        Top = ptr;
        return Top;
    }
}

Node *pop(Node *Top)
{
    if (isEmpty(Top))
    {
        cout << "-----------------------------------\n";
        cout << "Stack Underflow" << endl;
        return Top;
    }
    else
    {
        Node *ptr = new (Node);
        ptr = Top;
        Top = Top->next;
        free(ptr);
        return Top;
    }
}

void Traversal(Node *Top)
{
    cout << "-----------------------------------\n";
    Node *ptr = new (Node);
    ptr = Top;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void peek(Node *Top)
{
    Node *ptr = new (Node);
    cout << "Enter the position" << endl;
    int position;
    cin >> position;
    ptr = Top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        cout << "This position doesn't exist in the stack" << endl;
    }
    else
    {
        cout << "Value at " << position << " is: " << ptr->data << endl;
    }
}

int main()
{
    Node *Top = new (Node);
    int value;
    cout << "Enter the data" << endl;
    cin >> value;
    Top->data = value;
    Top->next = NULL;

    bool loop_iterator = true;
    while (loop_iterator)
    {
        cout << "-----------------------------------\n";
        int choice;
        cout << "Enter the choice\n1. Push\n2. Pop\n3. Traversal\n4. Peek\n5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Top = push(Top);
            continue;
        case 2:
            Top = pop(Top);
            continue;
        case 3:
            Traversal(Top);
            continue;
        case 4:
            peek(Top);
            continue;
        default:
            if (choice != 5)
            {
                cout << "Invalid Input" << endl;
            }
            loop_iterator = false;
        }
    }

    return 0;
}
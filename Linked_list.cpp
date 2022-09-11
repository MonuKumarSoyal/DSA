#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *Head)
{
    cout << "---------------------------------------------------\n";
    struct Node *ptr = new (struct Node);
    ptr = Head;
    cout << "Data inside the linked list" << endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// 1. Insertion at the beginning
struct Node *Insertion_at_beginning(struct Node *Head)
{
    cout << "---------------------------------------------------\n";
    struct Node *ptr = new (struct Node);
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    ptr->data = data;
    ptr->next = Head;
    return ptr;
}

// 2. Insertion at the index
struct Node *Insertion_at_index(struct Node *Head)
{
    cout << "---------------------------------------------------\n";
    // taking the data value and the index at which we will insert the node

    int data, index;
    cout << "Enter the data" << endl;
    cin >> data;
    cout << "Enter the index" << endl;
    cin >> index;
    // making the pointer of struct Node type

    struct Node *ptr = new (struct Node);
    struct Node *temp = new (struct Node);
    temp->data = data;
    ptr = Head;

    // if we don't want to insert at the beginning
    if (index != 0)
    {
        for (int i = 0; i < (index - 1); i++)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }

    // if we want to inset at the beginning
    else if (index == 0)
    {
        temp->next = ptr;
        return temp;
    }
    return Head;
}

// 3. Insertion at the end
void Insertion_at_end(struct Node *Head)
{
    cout << "---------------------------------------------------\n";
    struct Node *ptr = new (struct Node);
    struct Node *temp = new (struct Node);
    int data;
    cout << "Entet the data" << endl;
    cin >> data;
    temp->data = data;
    ptr = Head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    // now ptr is pointing the last element of the linked list
    ptr->next = temp;
    temp->next = NULL;
}

// 4. Insertion after the node

void Insertion_aftet_node(struct Node *node)
{
    cout << "---------------------------------------------------\n";
    struct Node *ptr = new (struct Node);
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;
}

// 5. Deletion at the beginning
struct Node *Deletion_at_the_beginning(struct Node *Head)
{
    struct Node *ptr = new (struct Node);
    ptr = Head;
    Head = Head->next;
    free(ptr);
    return Head;
}

// 6. Deletion at the given index

struct Node *Deletion_at_index(struct Node *Head)
{
    struct Node *ptr = new (struct Node); // this will point to a node
    ptr = Head;
    struct Node *temp = new (struct Node); // this is to point the node which is to be deleted.
    temp = Head->next;
    cout << "Enter the index" << endl;
    int index;
    cin >> index;
    if (index != 0)
    {
        for (int i = 0; i < (index - 1); i++)
        {
            ptr = ptr->next;
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = NULL;
        free(temp);
        return Head;
    }
    else if (index == 0)
    {
        return Deletion_at_the_beginning(Head);
    }
}

// 7. Deletion at the end

void Deletion_at_end(struct Node *Head)
{
    struct Node *ptr = new (struct Node);
    struct Node *temp = new (struct Node);
    ptr = Head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

// 8. Deletion after a node

void Deletion_after_node(struct Node *node)
{
    struct Node *ptr = new (struct Node);
    ptr = node->next;
    node->next = ptr->next;
    ptr->next = NULL;
    free(ptr);
}

int main()
{
    struct Node *first = new (struct Node);
    struct Node *second = new (struct Node);
    struct Node *third = new (struct Node);
    cout << "---------------------------------------------------\n";
    cout << "Enter the 3 datas" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cin >> first->data;
        }
        else if (i == 1)
        {
            cin >> second->data;
        }
        else
        {
            cin >> third->data;
        }
    }

    first->next = second;
    second->next = third;
    third->next = NULL;
    struct Node *Head = new (struct Node);
    Head = first;
    // Insertions at different places

    bool loop_terminator = true;

    while (loop_terminator)
    {
        int choice;
        cout << "---------------------------------------------------\n";
        cout << "Enter your choice\n1. Insertion at the beginning\n2. Insertion at the between\n3. Insertion at the end\n4. Insertion after a node\n---------------------------------------------------\n5. Traversal\n---------------------------------------------------\n6. Deletion at the beginning\n7. Deletion at the given index\n8. Deletion at the end\n9. Deletion after a node\n10. Exit\n---------------------------------------------------\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Head = Insertion_at_beginning(Head);
            break;
        case 2:
            Head = Insertion_at_index(Head);
            break;
        case 3:
            Insertion_at_end(Head);
            break;
        case 4:
            Insertion_aftet_node(second);
            break;
        case 5:
            Traversal(Head);
            break;
        case 6:
            Head = Deletion_at_the_beginning(Head);
            break;
        case 7:
            Head = Deletion_at_index(Head);
            break;
        case 8:
            Deletion_at_end(Head);
            break;
        case 9:
            Deletion_after_node(second);
            break;
        default:
            if (choice != 10)
            {
                cout << "Invalid Input" << endl;
            }
            loop_terminator = false;
        }
    }
    return 0;
}
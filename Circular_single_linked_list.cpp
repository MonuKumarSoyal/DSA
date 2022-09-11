#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){};
    Node(int value) { data = value; };
    Node(int value, Node *node)
    {
        data = value;
        next = node;
    }
};

void Traversal(Node *head)
{
    Node *ptr = new (Node);
    ptr = head;
    cout << "Element inside the Circular Linked List" << endl;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr->next != head);
    cout << ptr->data << endl;
}

// 1. Insertion at the beginnng
Node *Insertion_at_beginning(Node *head)
{
    Node *ptr = new (Node);
    ptr = head;
    Node *p = new (Node);
    cout << "Enter the data" << endl;
    cin >> p->data;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);

    ptr->next = p;
    p->next = head;
    return p;
}

// 2. Insertion at the given index
void Insertion_at_index(Node *head, int index)
{
    Node *ptr = new (Node);
    Node *p = new (Node);
    cout << "Enter the data" << endl;
    cin >> p->data;
    ptr = head;
    for (int i = 0; i < (index - 1); i++)
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
}

// 3. Insertion at the end
void Insertion_at_end(Node *head)
{
    Node *ptr = new (Node);
    Node *p = new (Node);
    cout << "Enter the data" << endl;
    cin >> p->data;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);

    ptr->next = p;
    p->next = head;
}

int main()
{
    Node *head = new (Node);
    Node *second = new (Node);
    Node *third = new (Node);
    Node *fourth = new (Node);
    Node *fifth = new (Node);

    // head node
    head->data = 5;
    head->next = second;

    // second node
    second->data = 15;
    second->next = third;

    // third node
    third->data = 25;
    third->next = fourth;

    // fourth node
    fourth->data = 35;
    fourth->next = fifth;

    // fifth node
    fifth->data = 45;
    fifth->next = head;

    // Traversaling the circular linked list
    Traversal(head);

    // Insertion at the beginning
    head = Insertion_at_beginning(head);
    Traversal(head);

    // Insertion at the given index
    Insertion_at_index(head, 3);
    Traversal(head);

    // Insertion at the end
    Insertion_at_end(head);
    Traversal(head);

    return 0;
}
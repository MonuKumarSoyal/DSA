#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;
    int *arr;
};

int isfull(stack *ptr)
{
    if (ptr->top >= ((ptr->size) - 1))
    {
        return 1;
    }
    return 0;
}

int isempty(stack *ptr)
{
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

int push(stack *ptr)
{
    cout << "------------------------------------------\n";
    int data;
    if (isfull(ptr))
    {
        cout << "Stack Overflow" << endl;
        return -1;
    }
    else
    {
        cout << "Enter the data" << endl;
        cin >> data;
        ptr->arr[++(ptr->top)] = data;
        return 0;
    }
}

void pop(stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "------------------------------------------\n";
        cout << "Stack Underflow" << endl;
    }
    else
    {
        ptr->top = (ptr->top) - 1;
    }
}

void Traversal(stack *ptr)
{
    int loop_terminator = 0;
    while (loop_terminator <= ptr->top)
    {
        cout << ptr->arr[loop_terminator] << " ";
        loop_terminator++;
    }
    cout << endl;
}

void peek(stack *ptr, int i)
{
    int index = ptr->top - i + 1;
    if (index < 0)
    {
        cout << "This position doesn't exist" << endl;
    }
    else
    {
        cout << "The value at position " << i << " is " << ptr->arr[index] << endl;
    }
}

void Stack_top(stack *ptr)
{
    cout << "The Stack Top value is: " << ptr->arr[ptr->top] << endl;
}

void Stack_bottom(stack *ptr)
{
    cout << "The Stack Bottom value is: " << ptr->arr[0] << endl;
}

int main()
{
    stack *stk = new (stack);
    cout << "------------------------------------------\n";
    cout << "Enter the size of the stack" << endl;
    cin >> stk->size;
    stk->arr = new int[stk->size];
    stk->top = -1;
    bool loop_terminator = true;
    int choice;
    while (loop_terminator)
    {
        cout << "------------------------------------------\n";
        cout << "Enter the choice\n1. Push\n2. Pop\n3. Traversal\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push(stk);
            continue;
        case 2:
            pop(stk);
            continue;
        case 3:
            Traversal(stk);
            continue;
        default:
            if (choice != 4)
            {
                cout << "Invalid Input" << endl;
            }
            loop_terminator = false;
        }
    }

    // using the peek fucntion
    for (int i = 1; i <= stk->top + 1; i++)
    {
        peek(stk, i);
    }

    // getting the Stack Top value
    Stack_top(stk);

    // getting the Stack Bottom value
    Stack_bottom(stk);
    return 0;
}
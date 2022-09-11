#include <iostream>
#include <string.h>
using namespace std;

class stack
{
public:
    int size;
    int top;
    char *arr;
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
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stack *ptr, char value)
{
    if (isfull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        ptr->arr[++(ptr->top)] = value;
    }
}

char pop(stack *ptr)
{
    if (isempty(ptr))
    {
        return -1;
    }
    else
    {
        char value;
        value = ptr->arr[ptr->top];
        ptr->top = (ptr->top) - 1;
        return value;
    }
}

char StackTop(stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

char *Infix_to_postfix(char *infix)
{
    stack *ptr = new (stack);
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = new char[ptr->size];
    int length = strlen(infix);

    // this string is to store the resultant postfix expression
    char *postfix = new char[length];
    int i = 0; // this is to traversal the infix string
    int j = 0; // this is to traversal the postfix string
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(StackTop(ptr)))
            {
                push(ptr, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(ptr);
                j++;
            }
        }
    }
    while (!isempty(ptr))
    {
        postfix[j] = pop(ptr);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = new char[100];
    cout << "Enter the expression" << endl;
    cin >> infix;

    char *postfix = Infix_to_postfix(infix);
    cout << "The postfix of the given expression is: " << postfix;

    return 0;
}
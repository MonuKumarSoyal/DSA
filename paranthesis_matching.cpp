#include <iostream>
#include <string>
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
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

int push(stack *ptr, char value)
{
    if (isfull(ptr))
    {
        cout << "Stack Overflow" << endl;
        return -1;
    }
    else
    {
        ptr->arr[++(ptr->top)] = value;
        return 0;
    }
}

int pop(stack *ptr)
{
    ptr->top = (ptr->top) - 1;
    return 1;
}

int parenthesis(string expression)
{
    stack *stk = new (stack);
    stk->size = 100;
    stk->top = -1;
    stk->arr = new char[stk->size];

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push(stk, '(');
        }
        else if (expression[i] == ')')
        {
            if (isempty(stk))
            {
                return 0;
            }
            pop(stk);
        }
    }

    if (isempty(stk))
    {
        return 1;
    }
    return 0;
}

int main()
{
    string parenthe = "(8*2)*(2+(3*4)-((24/4)+(33)))";
    if (parenthesis(parenthe))
    {
        cout << "Parenthesis are Balanced" << endl;
    }
    else
    {
        cout << "Parenthesis are not balanced" << endl;
    }
    return 0;
}
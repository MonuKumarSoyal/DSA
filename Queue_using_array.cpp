#include <iostream>
using namespace std;

class queue_structure
{
public:
    int size;
    int head;
    int tail;
    int *array;
};

int isEmpty(queue_structure *queue)
{
    if (queue->head == queue->tail)
    {
        return 1;
    }
    return 0;
}

int isFull(queue_structure *queue)
{
    if (queue->tail == (queue->size - 1))
    {
        return 1;
    }
    return 0;
}

int Enqueue(queue_structure *queue)
{
    if (isFull(queue))
    {
        cout << "Queue Overflow" << endl;
        return -1;
    }
    else
    {
        int Element;
        cout << "Enter the element" << endl;
        cin >> Element;
        queue->array[++(queue->tail)] = Element;
    }
    return 0;
}

int Dequeue(queue_structure *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    else
    {
        queue->head++;
        queue->size++;
    }
    return 0;
}

void Traversal(queue_structure *queue)
{
    for (int i = (queue->head + 1); i <= (queue->tail); i++)
    {
        cout << queue->array[i] << " ";
    }
    cout << endl;
}

int main()
{
    queue_structure *queue = new (queue_structure);
    queue->head = queue->tail = -1;

    cout << "Enter the size of the queue" << endl;
    cin >> queue->size;
    queue->array = new int[queue->size]; // we can put int[100] also.

    // here if we

    while (1)
    {
        int choice;
        cout << "Enter your choice\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Enqueue(queue);
            continue;
        case 2:
            Dequeue(queue);
            continue;
        case 3:
            Traversal(queue);
            continue;

        default:
            if (choice != 4)
            {
                cout << "Invalid Input" << endl;
            }
            return 0;
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

class circular_queue
{
public:
    int size;
    int head;
    int tail;
    int *array;
};

int isEmpty(circular_queue *queue)
{
    if (queue->head == -1 && queue->tail == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(circular_queue *queue)
{
    if ((queue->tail + 1) % queue->size == queue->head)
    {
        return 1;
    }
    return 0;
}

void Enqueue(circular_queue *queue)
{
    if (isFull(queue))
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        int value;
        cout << "Enter the value" << endl;
        cin >> value;
        queue->tail = (queue->tail + 1) % queue->size;
        queue->array[queue->tail] = value;
        if (queue->head == -1)
        {
            queue->head++;
        }
    }
}

void Dequeue(circular_queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        if (queue->head == queue->tail)
        {
            queue->head = queue->tail = -1;
        }
        else
        {
            queue->head = (queue->head + 1) % queue->size;
        }
    }
}

void Traversal(circular_queue *queue)
{
    int i = 0;
    while ((queue->head + i) % queue->size != queue->tail)
    {
        cout << queue->array[(queue->head + i) % queue->size] << " ";
        i++;
    }
    if (queue->tail != -1)
    {
        cout << queue->array[(queue->head + i) % queue->size] << " ";
    }
    cout << endl;
}

int main()
{

    circular_queue *queue = new (circular_queue);
    queue->tail = queue->head = -1;
    cout << "Enter the size of the queue" << endl;
    cin >> queue->size;
    queue->array = new int[queue->size];
    int choice;
    while (1)
    {
        cout << "Enter the choice\n1. Enqueue\n2. Dequeue\n3. Traversal\n4. Exit\n";
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
                cout << "Invalid Input";
            return 0;
        }
    }
}
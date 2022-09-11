#include <iostream>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
// int graph[7][7] = {
//     {1, 1, 1, 1, 0, 0, 0},
//     {1, 0, 1, 0, 0, 0, 0},
//     {0, 1, 0, 1, 0, 1, 1},
//     {0, 0, 1, 0, 1, 0, 0},
//     {0, 0, 0, 1, 0, 0, 0},
//     {0, 0, 1, 0, 0, 0, 0},
//     {0, 1, 0, 0, 0, 0, 0}};
int graph[7][7] = {
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0}};




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

int Enqueue(queue_structure *queue, int Element)
{
    if (isFull(queue))
    {
        cout << "Queue Overflow" << endl;
        return -1;
    }
    else
    {
        queue->array[++(queue->tail)] = Element;
    }
    return 0;
}

int Dequeue(queue_structure *queue)
{
    int temp;
    if (isEmpty(queue))
    {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    else
    {
        queue->head++;
        temp = queue->head;
        queue->size++;
    }
    return temp;
}

void BFS(queue_structure *queue, int i){
    visited[i] = 1;
    cout << i << " ";
    Enqueue(queue, i);

    while (!isEmpty(queue))
    {
        int node = Dequeue(queue);
        for (int i = 0; i < 7; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                Enqueue(queue, i);
            }
        }
    }

}

void DFS(int i){
    if(visited[i] != 1){
        cout<<i<<" ";
    }
    visited[i] = 1;
    for(int j = 0; j<7; j++){
        if(graph[i][j] == 1 && visited[j] != 1){
            DFS(j);
        }
    }
}

int main()
{
    queue_structure *queue = new (queue_structure);
    queue->head = queue->tail = -1;
    queue->size = 10;
    queue->array = new int[queue->size];


    cout<<"1. BFS\n2. DFS\n";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        BFS(queue, 0);
        break;
    case 2:
        DFS(0);
        break;    
    default:
        cout<<"Invalid input"<<endl;
        break;
    }

    return 0;
}
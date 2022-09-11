#include <iostream>
using namespace std;

void Traversal(int arr[], int capacity, int size)
{
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Insertion(int arr[], int capacity, int *size)
{
    cout << "----------------------------------------------------\n";
    if (*(size) >= capacity)
    {
        cout << "Overflow Case!" << endl;
    }
    else
    {
        int index, element;
        cout << "Enter the index" << endl;
        cin >> index;
        cout << "Enter the element" << endl;
        cin >> element;

        if (index >= capacity)
        {
            cout << "Space is not allocated" << endl;
        }
        else
        {
            for (int i = *(size); i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
            *(size) += 1;
            cout << element << " is inserted successfully" << endl;
        }
    }
}

void Deletion(int arr[], int capacity, int *size)
{
    if (size <= 0)
    {
        cout << "Underflow Case!" << endl;
    }
    else
    {
        cout << "----------------------------------------------------\n";
        int index;
        cout << "Enter the index" << endl;
        cin >> index;
        if (index >= *(size))
        {
            cout << "No Element is assigned there!" << endl;
        }
        else
        {
            for (int i = index; i < (*(size)-1); i++)
            {
                arr[i] = arr[i + 1];
            }
            *(size) -= 1;
            cout << "Element at index " << index << " deleted" << endl;
        }
    }
}

int main()
{
    cout << "----------------------------------------------------\n";
    int capacity, size;
    cout << "Enter the capacity of the array" << endl;
    cin >> capacity;
    int array[capacity];
    cout << "Enter the Used Size of the array" << endl;
    cin >> size;
    cout << "----------------------------------------------------\n";
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int num;
    bool loop_terminator = true;
    while (loop_terminator)
    {
        cout << "----------------------------------------------------\n";
        cout << "Select an operation\n1. Inserting\n2. Deleting\n3. Traversal\n4. Show Used Size\n5. Exit" << endl;
        cin >> num;
        switch (num)
        {
        case 1:
            Insertion(array, capacity, &size);
            continue;
        case 2:
            Deletion(array, capacity, &size);
            continue;
        case 3:
            Traversal(array, capacity, size);
            continue;
        case 4:
            cout << "The used size is " << size << endl;
            continue;

        default:
            if (num != 5)
            {
                cout << "Invalid Input" << endl;
            }
            loop_terminator = false;
        }
    }
    return 0;
}
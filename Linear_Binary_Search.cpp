#include <iostream>
using namespace std;

void Traversal(int arr[], int size)
{
    cout << "---------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int LinearSearch(int arr[], int size)
{
    cout << "---------------------------------------------\n";
    int element;
    cout << "Enter the element" << endl;
    cin >> element;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout << "Element " << element << " is found at index " << i << endl;
            return 0;
        }
    }
    cout << "Element " << element << " is not in array" << endl;
    return -1;
}

bool IsArraySorted(int arr[], int size)
{
    if (size != 1)
    {
        if (arr[0] <= arr[1])
        {
            for (int i = 0; i < size - 1; i++)
            {
                if (arr[i] <= arr[i + 1])
                {
                }
                else
                {
                    return false;
                }
            }
        }
        if (arr[0] >= arr[1])
        {
            for (int i = 0; i < size - 1; i++)
            {
                if (arr[i] >= arr[i + 1])
                {
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return true;
    }
}

int BinarySearch(int arr[], int size)
{
    if (IsArraySorted(arr, size))
    {
        cout << "---------------------------------------------\n";
        int element;
        cout << "Enter the element" << endl;
        cin >> element;
        int low, mid, high;
        low = 0;
        high = size - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] == element)
            {
                cout << "Element " << element << " is found at index " << mid << endl;
                return 0;
            }
            if (arr[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "Elment " << element << " is not in array" << endl;
    }
    else
    {
        cout << "---------------------------------------------\n";
        cout << "Array is not sorted" << endl;
    }
}

int main()
{
    cout << "---------------------------------------------\n";
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int array[size];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    int choice;
    bool loop_terminator = true;
    while (loop_terminator)
    {
        cout << "---------------------------------------------\n";
        cout << "Enter your choice\n1. Linear Search\n2. Binary Search\n3. Show Array\n4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            LinearSearch(array, size);
            continue;
        case 2:
            BinarySearch(array, size);
            continue;
        case 3:
            Traversal(array, size);
            continue;
        default:
            if (choice != 4)
            {
                cout << "Invalid input!" << endl;
            }
            loop_terminator = false;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

void Bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << "Pass number " << i + 1 << endl;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}

// below function is performing a adaptive bubble sort algorithm

void Bubble_sort_adaptive(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int loop_terminator = 1;
        cout << "Pass number " << i + 1 << endl;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                loop_terminator = 0;
            }
        }
        if (loop_terminator == 1)
        {
            break;
        }
    }
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter the size of the array" << endl;
    int size;
    cin >> size;
    int arr[size];
    cout << "Enter the element in the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // Bubble_sort(arr, size);
    Bubble_sort_adaptive(arr, size);

    return 0;
}
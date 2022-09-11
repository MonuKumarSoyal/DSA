#include <iostream>
using namespace std;

void Traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i, int index_of_min)
{
    int temp = arr[index_of_min];
    arr[index_of_min] = arr[i];
    arr[i] = temp;
}

void Selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int index_of_min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[index_of_min] > arr[j])
            {
                index_of_min = j;
            }
        }
        swap(arr, i, index_of_min);
    }
}

int main()
{
    cout << "Enter the size of the array" << endl;
    int size;
    cin >> size;
    int arr[size];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Given array is: ";
    Traversal(arr, size);
    Selection_sort(arr, size);
    cout << "Sorted array is: ";
    Traversal(arr, size);

    return 0;
}
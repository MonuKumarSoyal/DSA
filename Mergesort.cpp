#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    cout << "Elements in the array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int arr[], int low, int mid, int high)
{
    int array[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            array[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            array[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        array[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        array[k] = arr[j];
        k++;
        j++;
    }
    for (int x = low; x <= high; x++)
    {
        arr[x] = array[x];
    }
}

void mergesort(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
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
    print(arr, size);
    mergesort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}
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

void CountSort(int array[], int size)
{
    int temp = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > temp)
        {
            temp = array[i];
        }
    }
    int arr[temp + 1]; // this array will store the count of the element according to their occurance
    for (int i = 0; i < temp + 1; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        arr[array[i]] = arr[array[i]] + 1;
    }
    int index = 0; // this is to store the index of the original array
    for (int i = 0; i < temp + 1; i++)
    {
        while (arr[i] != 0)
        {
            array[index] = i;
            arr[i] = arr[i] - 1;
            index++;
        }
    }
}

int main()
{
    cout << "Enter the size of the array" << endl;
    int size;
    cin >> size;
    int array[size];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    print(array, size);
    CountSort(array, size);
    print(array, size);
    return 0;
}
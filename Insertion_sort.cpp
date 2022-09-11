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

void Insertion_sort(int arr[], int size)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// this will also work

// void insertionSort(int A[], int n){
//     int key, j;
//     // Loop for passes
//     for (int i = 1; i <= n-1; i++)
//     {
//         key = A[i];
//         j = i-1;
//         // Loop for each pass
//         while(j>=0 && A[j] > key){
//             A[j+1] = A[j];
//             j--;
//         }
//         A[j+1] = key;
//     }
// }

int main()
{
    cout << "Enter the size of the array" << endl;
    int size;
    cin >> size;

    // int *arr = new int[size];
    int arr[size];
    cout << "Enter the elements in the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Given array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    Insertion_sort(arr, size);
    Traversal(arr, size);
    return 0;
}
#include <iostream>
using namespace std;

class Array
{
    int Total_size;
    int Used_size;
    int *arr;

public:
    Array(int t_size, int u_size)
    {
        Total_size = t_size;
        Used_size = u_size;
        arr = new int[t_size];
    }
    void set_array();
    void show_array();
};

void Array ::set_array()
{
    cout << "Enter the element" << endl;
    for (int i = 0; i < Used_size; i++)
    {
        cin >> arr[i];
    }
}

void Array ::show_array()
{
    cout << "Elements present in the array" << endl;
    for (int i = 0; i < Used_size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int total_size, used_size;
    cout << "Enter the Total size and used size of the array" << endl;
    cin >> total_size >> used_size;
    Array array(total_size, used_size);
    array.set_array();
    array.show_array();
    return 0;
}
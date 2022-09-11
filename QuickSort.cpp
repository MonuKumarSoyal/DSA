#include<iostream>
using namespace std;

void Printarray(int array[], int size){
    cout<<"Elements in the array: ";
    for(int i = 0; i< size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int partition(int array[], int low, int high){
    int i = low;
    int j = high + 1;
    int temp = array[low];
    while(j>i){
        do
        {
            i++;
        }while (array[i]<temp && i<high);

        do
        {
            j--;
        }while (array[j]>temp && j >= low+1);
        
        if(i<j){
            int temp1 = array[i];
            array[i] = array[j];
            array[j] = temp1;
        }   
    }
    if(j<=i){
        array[low] = array[j];
        array[j] = temp;
    }
    return j;
    
}

void QuickSort(int array[], int low, int high){
    int pivot_index;
    if(low < high){
        pivot_index = partition(array, low, high);
        QuickSort(array, low, pivot_index - 1);
        QuickSort(array, pivot_index+1, high);
    }
}

int main(){
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter the elements in the array"<<endl;
    for(int i = 0; i<size; i++){
        cin>>array[i];
    }
    Printarray(array, size);
    QuickSort(array, 0, size-1);
    Printarray(array, size);
    return 0;
}
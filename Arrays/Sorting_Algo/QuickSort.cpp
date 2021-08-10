#include<bits/stdc++.h>
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
/*
This function takes last element as pivot,  places the pivot element at its correct position in sorted array, and places all smaller(smaller than pivot) to left of pivot and all greater elements to right of pivot
*/
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int indexOfSmallerElement = (low - 1);
    for(int currentElement=low; currentElement<=high; currentElement++){
        if(arr[currentElement] < pivot)
        {
            indexOfSmallerElement ++;
            swap(arr[indexOfSmallerElement], arr[currentElement]);
        }
    }
    swap(arr[indexOfSmallerElement + 1], arr[high]);

    return (indexOfSmallerElement + 1);

}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low , high);

        quickSort(arr, low, pivot-1);// Before Pivot
        quickSort(arr, pivot+1, high);// After Pivot

    }
}

int main()
{
    int array[]= {3,2,6,4,87,54,97};
    for(int i: array){
        cout << i <<"  ";
    }
    cout<<"\n";
    quickSort(array, 0, 6);
    for(int i: array){
        cout << i <<"  ";
    }
    return 0;
}
#include <iostream>
#include "08_sortAlg.cpp"


using namespace std;


// Example usage
int main() {
    int arr[] = {0,10,20,1,2,12,22};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    // Test Insertion Sort
    insertionSort(arr, size);
    cout << "Insertion Sorted array: ";
    printArray(arr, size);

    // Reset array
    int arr2[] = {0,10,20,1,2,12,22};
    selectionSort(arr2, size);
    cout << "Selection Sorted array: ";
    printArray(arr2, size);

    // Reset array
    int arr3[] = {0,10,20,1,2,12,22};
    bubbleSort(arr3, size);
    cout << "Bubble Sorted array: ";
    printArray(arr3, size);

    cout << "counter comparisons: Insertion Sort: " << ins_count << " Selection Sort: " << sel_count << " Bubble Sort: " << bub_count << endl;

    /*
    Original array: 0 10 20 1 2 12 22 
    Insertion Sorted array: 0 1 2 10 12 20 22
    Selection Sorted array: 0 1 2 10 12 20 22
    Bubble Sorted array: 0 1 2 10 12 20 22
    counter comparisons: Insertion Sort: 11 Selection Sort: 21 Bubble Sort: 15
    */


}
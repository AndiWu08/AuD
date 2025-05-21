#include <iostream>
using namespace std;

int ins_count, sel_count, bub_count = 0;

// Insertion Sort
void insertionSort(int arr[], int size) {

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare key with each element on the left of it until an element smaller than it is found
        while (j >= 0) {
            ins_count++; 
            if (arr[j] > key) {
                arr[j + 1] = arr[j]; 
                j--;
            } else {
                break; 
            }
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find the minimum element in unsorted array
        for (int j = i + 1; j < size; j++) {
            sel_count++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++) {
            bub_count++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps occurred, array is sorted
        if (!swapped)
            break;
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

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
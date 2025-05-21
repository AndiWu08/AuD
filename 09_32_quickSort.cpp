#include <iostream>
using namespace std;

// Partition function using last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than pivot
        if (arr[j] < pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return partition index
}

// Main Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {0, 10, 20, 1, 2, 12, 22};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array:   ";
    printArray(arr, size);

    int arr2[9] = {0, 10, 20, 1, 11, 21, 2, 12, 22};
    partition(arr2, 0, 8);
    printArray(arr2, 9);    
}
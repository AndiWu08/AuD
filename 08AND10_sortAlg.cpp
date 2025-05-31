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

#include <iostream>
using namespace std;

// Partition function using last element as pivot
int partition(int arr[], int low, int high) {
    // choose random index and make it the pivot element
    // int randomIndex = low + rand() % (high - low +1);
    // swap(arr[randomIndex], arr[high]);

    // choose median as pivot
    int medianIndex = (low + high) / 2;
    swap(arr[medianIndex], arr[high]);

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

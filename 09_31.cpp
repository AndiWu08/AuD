#include <iostream>
using namespace std;

int bub_count = 0;

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

    bubbleSort(arr, size);
    cout << "Bubble Sorted array: ";
    printArray(arr, size);
    cout << bub_count << endl;
}
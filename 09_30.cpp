#include "08_sortAlg.cpp"

int main() {
    int arr1[] = {0,10,20};
    int arr2[] = {0,10,20,1,2,12};
    int arr3[] = {0,10,20,1,2,12,22,35,3};
    int arr4[] = {0,10,20};
    int arr5[] = {0,10,20,1,2,12};
    int arr6[] = {0,10,20,1,2,12,22,35,3};
    int arr7[] = {0,10,20};
    int arr8[] = {0,10,20,1,2,12};
    int arr9[] = {0,10,20,1,2,12,22,35,3};

    std::cout << "Insertion Sort:" << std::endl;
    insertionSort(arr1, 3);
    std::cout << ins_count << endl; // 2
    insertionSort(arr2, 6);
    std::cout << ins_count << endl; // 12
    insertionSort(arr3, 9);
    std::cout << ins_count << endl; // 30

    std::cout << "Selection Sort:" << std::endl;
    selectionSort(arr1, 3);
    std::cout << sel_count << endl; // 3
    selectionSort(arr2, 6);
    std::cout << sel_count << endl; // 18
    selectionSort(arr3, 9);
    std::cout << sel_count << endl; // 54

    std::cout << "Bubble Sort:" << std::endl;
    bubbleSort(arr1, 3);
    std::cout << bub_count << endl; // 2
    bubbleSort(arr2, 6);
    std::cout << bub_count << endl; // 7
    bubbleSort(arr3, 9);
    std::cout << bub_count << endl; // 15
}
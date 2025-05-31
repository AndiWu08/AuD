#include "08AND10_sortAlg.cpp"
#include <cstdlib>
#include <ctime>
#include <chrono>

void fill_array(int arr[], int size) {
    // fill array with random numbers
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

int main() {
    srand(time(0));
    int arr1[50];
    int arr2[500];
    
    // sort arrays using insertionSort
    fill_array(arr1, 50);
    auto start_in1 = std::chrono::high_resolution_clock::now();
    insertionSort(arr1, 50);
    auto end_in1 = std::chrono::high_resolution_clock::now();

    fill_array(arr2, 500);
    auto start_in2 = std::chrono::high_resolution_clock::now();
    insertionSort(arr2, 500);
    auto end_in2 = std::chrono::high_resolution_clock::now();

    // sort using quick sort
    fill_array(arr1, 50);
    auto start_qs1 = std::chrono::high_resolution_clock::now();
    quickSort(arr1, 0, 50 - 1);
    auto end_qs1 = std::chrono::high_resolution_clock::now();

    fill_array(arr2, 500);
    auto start_qs2 = std::chrono::high_resolution_clock::now();
    quickSort(arr2, 0, 500 - 1);
    auto end_qs2 = std::chrono::high_resolution_clock::now();

    // calculate needed time for each sorting
    std::chrono::duration<double> dur_in1 = end_in1 - start_in1;
    std::chrono::duration<double> dur_in2 = end_in2 - start_in2;
    std::chrono::duration<double> dur_qs1 = end_qs1 - start_qs1;
    std::chrono::duration<double> dur_qs2 = end_qs2 - start_qs2;

    std::cout << "Insertion Sort arr1:" << dur_in1.count() << " Sekunden" << std::endl;
    std::cout << "Quick Sort arr1:" << dur_qs1.count() << " Sekunden" << std::endl;
    std::cout << "Insertion Sort arr2:" << dur_in2.count() << " Sekunden" << std::endl;
    std::cout << "Quick Sort arr2:" << dur_qs2.count() << " Sekunden" << std::endl;
}
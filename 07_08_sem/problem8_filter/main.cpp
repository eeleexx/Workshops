///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Filter Array
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int))`
/// that filters an array based on a predicate function and returns a new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int)) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (filterFunc(arr[i])) {
            newSize++;
        }
    }

    int* filteredArr = new int[newSize];

    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (filterFunc(arr[i])) {
            filteredArr[j++] = arr[i];
        }
    }
    
    return filteredArr;

}

bool CheckEven(int x) {
    return x % 2 == 0;
}



int main() {

    int arr[5];

    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize;

    int* filteredArr = filter(arr, size, newSize, CheckEven);

    for (int i = 0; i < newSize; ++i) {
        std::cout << filteredArr[i] << " ";
    }
    std::cout << "\n";
    
    delete[] filteredArr;

    return 0;
}

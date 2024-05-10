///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Array Transformation
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void transformArray(int* arr, int size, int (*transform)(int))`
/// that applies a transformation function to each element of an array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int transformFunction(int x) {
    return x + 1;
}

void transformArray(int* arr, int size, int (*transform)(int)) {
    for(int i = 0; i < size; ++i) {
        arr[i] = transform(arr[i]);
    }
}

int main() {

    int arr[5];

    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);


    transformArray(arr, size, transformFunction);

    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }


    return 0;

}
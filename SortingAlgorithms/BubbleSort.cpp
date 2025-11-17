// Bubble Sort Algorithm Implementation

#include <iostream>
#include <vector>
#include <chrono>

// implementation 1: Bubble Sort Algorithm
// sudo code
// 1. Get the size of the array
// 2. Loop through the array elements
// 3. Compare adjacent elements
// 4. Swap if they are in the wrong order
// 5. Repeat until the array is sorted

// complexity: O(n^2)

void bubbleSort(std::vector<int>& arr){
    int size = arr.size(); // Get the size of the array
    for(int index = 0; index < size - 1; ++index){ // Loop through the array elements
        for(int j = 0; j < size - index - 1; ++j){ // Compare adjacent elements
            if(arr[j] > arr[j + 1]){ // If they are in the wrong order
                std::swap(arr[j], arr[j + 1]); // Swap them
            }
        }
    }
    std::cout << "Sorted Array: ";
    for(const int& num : arr){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5, 78, 45, 89, 23, 67, 88, 1, 3, 99, 54, 32, 76};
    std::cout << "Original Array: ";
    for(const int& num : arr){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // measurement start
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken by Bubble Sort: " << duration.count() << " ms" << std::endl;
    return 0;
}
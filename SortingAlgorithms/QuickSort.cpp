// QuickSort implementation in C++
#include <iostream>
#include <vector>
#include <chrono>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high){

    int pivot = arr[high]; // Taking the last element as pivot
    int i = low-1; // To keep track of the smaller element index
    // Rearranging the array elements based on the pivot
    for(int j = low; j <= high -1; j++){
        // If current element is smaller than the pivot
        if(arr[j] < pivot){

            i++; // Increment index of smaller element
            std::swap(arr[i], arr[j]); // Swap the element that is smaller than pivot
        }
    }
    std::swap(arr[i + 1], arr[high]); // Place the pivot element at the correct position
    return i + 1;  // Return the pivot index
}

// QuickSort function
void quickSort(std::vector<int>& arr, int low, int high){

    // Base case
    if(low < high){  // If there are at least two elements to sort
        // Partitioning the array
        int pivot = partition(arr, low, high); // pivot is now at the right place
        quickSort(arr, low, pivot - 1); // Recursively sort elements before partition
        quickSort(arr, pivot + 1, high); // Recursively sort elements after partition
    }
}

int main(){
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5, 78, 45, 89, 23, 67, 88, 1, 3, 99, 54, 32, 76};
    int n = arr.size();
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr,0,n-1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "QuickSort took " << duration.count() << " milliseconds." << std::endl;

    return 0;
}
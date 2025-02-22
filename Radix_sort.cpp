#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Counting Sort based on the digit represented by exp (1, 10, 100, ...)
void countingSort(int arr[], int n, int exp) {
    const int RADIX = 10; // Base 10 for decimal numbers
    vector<int> output(n); // Output array to store sorted numbers
    vector<int> count(RADIX, 0); // Count array to store frequency of digits

    // Count occurrences of each digit at the current place value (exp)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % RADIX;
        count[digit]++;
    }

    // Update count[i] to store the actual position of the digit in output[]
    for (int i = 1; i < RADIX; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in their correct positions
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % RADIX;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted numbers back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int maxVal = getMax(arr, n);

    // Perform counting sort for every digit (LSD to MSD)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Utility function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Perform Radix Sort
    radixSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

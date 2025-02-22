#include <iostream>
using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform Insertion Sort for the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Store the current element
            int j;

            // Shift earlier gap-sorted elements up until the correct location is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Place the current element in its correct location
            arr[j] = temp;
        }
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
    int arr[] = {8, 5, 3, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Perform Shell Sort
    shellSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}

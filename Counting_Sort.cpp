#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Find the maximum and minimum values in the array
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    // Step 2: Calculate the range of values (k)
    int range = maxVal - minVal + 1;

    // Step 3: Initialize the count array with zeros
    vector<int> count(range, 0);

    // Step 4: Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    // Step 5: Transform the count array into a cumulative count array
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Step 6: Build the output array
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) { // Traverse in reverse to maintain stability
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // Step 7: Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original Array: ";
    printArray(arr);

    // Perform Counting Sort
    countingSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}

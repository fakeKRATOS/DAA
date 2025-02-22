#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Step 1: Create empty buckets
    vector<vector<float>> buckets(n);

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = n * arr[i]; // Calculate bucket index
        buckets[bucket_index].push_back(arr[i]);
    }

    // Step 3: Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end()); // Use STL sort
    }

    // Step 4: Concatenate all buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}

// Utility function to print the array
void printArray(const vector<float>& arr) {
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Original Array: ";
    printArray(arr);

    // Perform Bucket Sort
    bucketSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}

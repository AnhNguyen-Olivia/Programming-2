#include <iostream>      // Include input/output stream library for cin/cout
#include <stdlib.h>      // Include standard library for calloc and free
using namespace std;     // Use the standard namespace

// Define a class for Merge Sort functionality
class MergeSorter {
public:
    // Constructor: takes a pointer to an array and its size
    MergeSorter(int* arr, int size) : arr(arr), size(size) {}

    // Public method to start the sorting process
    void sort() {
        MergeSort(0, size - 1); // Call MergeSort on the entire array
    }

private:
    int* arr;   // Pointer to the array to be sorted
    int size;   // Size of the array

    // Recursive MergeSort function
    void MergeSort(int left, int right) {
        if (left < right) { // If there are at least two elements
            int mid = left + (right - left) / 2; // Find the middle index
            MergeSort(left, mid);        // Sort the left half
            MergeSort(mid + 1, right);   // Sort the right half
            Merge(left, mid, right);     // Merge the two halves
        }
    }

    // Merge two sorted subarrays into one sorted array
    void Merge(int left, int mid, int right) {
        int n1 = mid - left + 1;    // Size of left subarray
        int n2 = right - mid;       // Size of right subarray
        int* Left = new int[n1];    // Allocate memory for left subarray
        int* Right = new int[n2];   // Allocate memory for right subarray

        // Copy data to temporary left subarray
        for (int i = 0; i < n1; i++) {
            Left[i] = arr[left + i];
        }
        // Copy data to temporary right subarray
        for (int j = 0; j < n2; j++) {
            Right[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left; // Initialize indices for Left, Right, and arr

        // Merge the temp arrays back into arr
        while (i < n1 && j < n2) {
            if (Left[i] <= Right[j]) {
                arr[k] = Left[i]; // Take from Left if smaller or equal
                i++;
            } else {
                arr[k] = Right[j]; // Take from Right if smaller
                j++;
            }
            k++;
        }

        // Copy any remaining elements of Left
        while (i < n1) {
            arr[k] = Left[i];
            i++;
            k++;
        }

        // Copy any remaining elements of Right
        while (j < n2) {
            arr[k] = Right[j];
            j++;
            k++;
        }

        delete[] Left;   // Free memory for Left subarray
        delete[] Right;  // Free memory for Right subarray
    }
};

int main() {
    int* arr;   // Pointer for the array
    int num, i; // Variables for number of elements and loop index

    cout << "How many numbers do you want to enter?: ";
    cin >> num; // Read the number of elements

    arr = (int*)calloc(num, sizeof(int)); // Allocate memory for array

    if (arr == NULL) { // Check if memory allocation failed
        cout << "Memory allocation failed\n";
        return 1; // Exit with error code
    }

    // Input numbers from the user
    for (i = 0; i < num; i++) {
        cout << "Please enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Display the entered numbers
    cout << "You have entered: ";
    for (i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    MergeSorter sorter(arr, num); // Create a MergeSorter object
    sorter.sort();                // Sort the array

    // Display the sorted array
    cout << "Sorted array: ";
    for (i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    free(arr); // Free the allocated memory
    return 0;  // End of program
}
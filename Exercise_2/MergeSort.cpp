#include <iostream>
#include <stdlib.h>
using namespace std;

void Merge(int arr[], int left, int mid, int right);

void MergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void Merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *Left = new int[n1];
    int *Right = new int[n2];

    for(int i = 0; i < n1; i++){
        Left[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        Right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
        }else{
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = Left[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = Right[j];
        j++;
        k++;
    }

    delete[] Left;
    delete[] Right;
}

int main() {
    int *arr;
    int num, i;

    cout << "How many numbers do you want to enter?: ";
    cin >> num;

    arr = (int*) calloc(num, sizeof(int)); // arr becomes an array of size num

    if (arr == NULL) {
        cout << "Memory allocation failed\n"; // return 1 if failed
        return 1;
    }

    for (i = 0; i < num; i++) {
        cout << "Please enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Check if the input is successful
    cout << "You have entered: ";
    for (i = 0; i < num; i++) {
        cout << arr[i] << " "; // print the value of the array element
    }
    cout << "\n";

    // Call MergSort to sort the array
    MergeSort(arr, 0, num - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    free(arr);
    return 0;
}
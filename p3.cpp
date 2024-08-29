#include <iostream>
using namespace std;

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x) {
            return m;
        }

        // If x greater, ignore left half
        if (arr[m] < x) {
            l = m + 1;
        }
        // If x is smaller, ignore right half
        else {
            r = m - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Apply insertion sort
    insertionSort(arr, N);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform binary search
    int x;
    cout << "Enter the number to search for: ";
    cin >> x;

    int result = binarySearch(arr, 0, N - 1, x);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class ArrayOperations {
private:
    vector<int> arr;

public:
    // Constructor to initialize the array with N values
    ArrayOperations(int N) {
        cout << "Enter " << N << " values: ";
        for (int i = 0; i < N; ++i) {
            int value;
            cin >> value;
            arr.push_back(value);
        }
    }

    // Function to perform insertion sort
    void insertionSort() {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    // Function to perform binary search
    int binarySearch(int key) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Key not found
    }

    // Function to display the array
    void displayArray() {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    ArrayOperations arrayOps(N);

    cout << "Array before sorting: ";
    arrayOps.displayArray();

    arrayOps.insertionSort();

    cout << "Array after sorting: ";
    arrayOps.displayArray();

    int key;
    cout << "Enter the value to search: ";
    cin >> key;

    int result = arrayOps.binarySearch(key);
    if (result != -1) {
        cout << "Value found at index: " << result << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}
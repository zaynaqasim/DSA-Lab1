#include <iostream>
#include <vector>
using namespace std;

// Function to find the mode (most frequent element)
int findMode(const vector<int>& arr) {
    if (arr.empty()) return -1;

    int mode = arr[0];
    int maxCount = 0;

    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int num : arr) cout << num << " ";
    cout << "]";
}

// Test Case 1: Unique mode
void testCase1() {
    cout << "Test Case 1: Unique Mode" << endl;
    vector<int> arr = { 1, 2, 2, 3, 4 };
    printArray(arr);
    cout << "Mode = " << findMode(arr) << endl << endl;
}

// Test Case 2: Multiple modes
void testCase2() {
    cout << "Test Case 2: Multiple Modes" << endl;
    vector<int> arr = { 1, 1, 2, 2, 3 };
    printArray(arr);
    cout << "Mode = " << findMode(arr) << endl << endl;
}

// Test Case 3: Empty array
void testCase3() {
    cout << "Test Case 3: Empty Array" << endl;
    vector<int> arr = {};
    printArray(arr);
    cout << "Mode = " << findMode(arr) << endl << endl;
}
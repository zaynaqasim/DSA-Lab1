#include <iostream>
#include <vector>
using namespace std;

vector<int> findIndices(const double* arr, int n, double key) {
    vector<int> output;
    if (n <= 0 || arr == nullptr) return output;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) output.push_back(i);
    }
    return output;
}

void testCase1() {
    double arr[] = { 56.3, 29.11, 20, 2, 56.3, 56.3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    double key = 56.3;

    vector<int> indices = findIndices(arr, n, key);

    cout << "\nTest Case 1: Multiple Occurrences\n";
    if (indices.empty()) {
        cout << "The key is absent\n";
    }
    else {
        cout << "The key is found at indices: ";
        for (int idx : indices) cout << idx << " ";
        cout << endl;
    }
}

void testCase2() {
    double arr[] = { 12, 632.111, 3878.11, 2, 95 };
    int n = sizeof(arr) / sizeof(arr[0]);
    double key = 3;

    vector<int> indices = findIndices(arr, n, key);

    cout << "\nTest Case 2: Absent Key\n";
    if (indices.empty()) {
        cout << "The key is absent\n";
    }
    else {
        cout << "The key is found at indices: ";
        for (int idx : indices) cout << idx << " ";
        cout << endl;
    }
}

void testCase3() {
    const double* arr = nullptr;
    int n = 0;
    double key = 1;

    vector<int> indices = findIndices(arr, n, key);

    cout << "\nTest Case 3: Empty Array\n";
    if (indices.empty()) {
        cout << "The key is absent\n";
    }
    else {
        cout << "The key is found at indices: ";
        for (int idx : indices) cout << idx << " ";
        cout << endl;
    }
}
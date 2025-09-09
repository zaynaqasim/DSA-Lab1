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


int main() {
    testCase1();
    testCase2();
    testCase3();
    return 0;
}
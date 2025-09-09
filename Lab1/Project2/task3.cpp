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

int main() {
    testCase1();
    testCase2();
    testCase3();
    return 0;
}

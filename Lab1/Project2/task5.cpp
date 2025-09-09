
#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalsTriangle(int n) {
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1); // first and last elements are always 1
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

// Utility function to print Pascal's Triangle
void printTriangle(const vector<vector<int>>& triangle) {
    for (auto row : triangle) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}


int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    return 0;
}

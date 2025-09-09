
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

// Test Case 1: n = 0
void testCase1() {
    cout << "--- Test Case 1: n = 0 ---" << endl;
    auto triangle = generatePascalsTriangle(0);
    printTriangle(triangle); // Expected: nothing (empty)
    cout << endl;
}

// Test Case 2: n = 1
void testCase2() {
    cout << "--- Test Case 2: n = 1 ---" << endl;
    auto triangle = generatePascalsTriangle(1);
    printTriangle(triangle); // Expected: 1
    cout << endl;
}

// Test Case 3: n = 5
void testCase3() {
    cout << "--- Test Case 3: n = 5 ---" << endl;
    auto triangle = generatePascalsTriangle(5);
    printTriangle(triangle);
    cout << endl;
}

// Test Case 4: Verify row 5 = {1, 4, 6, 4, 1}
void testCase4() {
    cout << "--- Test Case 4: Verify row 5 ---" << endl;
    auto triangle = generatePascalsTriangle(5);
    vector<int> expected = { 1, 4, 6, 4, 1 };
    vector<int> row5 = triangle[4]; // row index starts at 0

    cout << "Row 5: ";
    for (int val : row5) cout << val << " ";
    cout << endl;

    cout << "Expected: ";
    for (int val : expected) cout << val << " ";
    cout << endl << endl;
}
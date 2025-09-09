#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
using namespace std;

using Matrix = vector<vector<int>>;

// Utility: Print matrix
void printMatrix(const Matrix& M) {
    for (auto& row : M) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << endl;
}

// Standard Matrix Multiplication
Matrix multiplyNaive(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Matrix addition
Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Matrix subtraction
Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen’s Algorithm
Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = n / 2;
    Matrix a11(newSize, vector<int>(newSize));
    Matrix a12(newSize, vector<int>(newSize));
    Matrix a21(newSize, vector<int>(newSize));
    Matrix a22(newSize, vector<int>(newSize));
    Matrix b11(newSize, vector<int>(newSize));
    Matrix b12(newSize, vector<int>(newSize));
    Matrix b21(newSize, vector<int>(newSize));
    Matrix b22(newSize, vector<int>(newSize));

    // Split A and B into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute the 7 products (Strassen)
    Matrix p1 = strassen(a11, subtract(b12, b22));
    Matrix p2 = strassen(add(a11, a12), b22);
    Matrix p3 = strassen(add(a21, a22), b11);
    Matrix p4 = strassen(a22, subtract(b21, b11));
    Matrix p5 = strassen(add(a11, a22), add(b11, b22));
    Matrix p6 = strassen(subtract(a12, a22), add(b21, b22));
    Matrix p7 = strassen(subtract(a11, a21), add(b11, b12));

    // Compute result quadrants
    Matrix c11 = add(subtract(add(p5, p4), p2), p6);
    Matrix c12 = add(p1, p2);
    Matrix c21 = add(p3, p4);
    Matrix c22 = subtract(subtract(add(p5, p1), p3), p7);

    // Combine submatrices into result
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return C;
}

// Compare two matrices
bool areEqual(const Matrix& A, const Matrix& B) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != B[i][j]) return false;
    return true;
}


// Test Case 1: 2x2 matrix multiplication
void testCase1() {
    cout << "Test Case 1: 2x2 Matrix\n";
    Matrix A = { {1, 2}, {3, 4} };
    Matrix B = { {5, 6}, {7, 8} };

    Matrix naive = multiplyNaive(A, B);
    Matrix stras = strassen(A, B);

    cout << "Naive Result:\n"; printMatrix(naive);
    cout << "Strassen Result:\n"; printMatrix(stras);
    cout << "Match? " << (areEqual(naive, stras) ? "Yes" : "No") << "\n\n";
}

// Test Case 2: 4x4 matrix multiplication
void testCase2() {
    cout << "Test Case 2: 4x4 Matrix\n";
    Matrix A = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    Matrix B = { {16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1} };

    Matrix naive = multiplyNaive(A, B);
    Matrix stras = strassen(A, B);

    cout << "Naive Result:\n"; printMatrix(naive);
    cout << "Strassen Result:\n"; printMatrix(stras);
    cout << "Match? " << (areEqual(naive, stras) ? "Yes" : "No") << "\n\n";
}

// Test Case 3: Random values
void testCase3() {
    cout << "Test Case 3: Random 4x4 Matrix\n";
    srand(time(0));

    int n = 4;
    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    cout << "Matrix A:\n"; printMatrix(A);
    cout << "Matrix B:\n"; printMatrix(B);

    Matrix naive = multiplyNaive(A, B);
    Matrix stras = strassen(A, B);

    cout << "Naive Result:\n"; printMatrix(naive);
    cout << "Strassen Result:\n"; printMatrix(stras);
    cout << "Match? " << (areEqual(naive, stras) ? "Yes" : "No") << "\n\n";
}
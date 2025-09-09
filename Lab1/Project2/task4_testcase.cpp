#include <string>
#include <iostream>
using namespace std;

int findFirstOccurrence(string text, string pattern) {
    if (pattern.empty()) return -1;

    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) return i;
    }
    return -1;
}

// Test Case 1: Pattern at the beginning
void testCase1() {
    string text = "sunny day";
    string pattern = "sunny";
    cout << "Test Case 1: Pattern at the beginning\n";
    cout << "Result: " << findFirstOccurrence(text, pattern) << endl;
}

// Test Case 2: Pattern at the end
void testCase2() {
    string text = "this is another test case";
    string pattern = "case";
    cout << "Test Case 2: Pattern at the end\n";
    cout << "Result: " << findFirstOccurrence(text, pattern) << endl;
}

// Test Case 3: Pattern not present
void testCase3() {
    string text = "pattern is not present";
    string pattern = "it exists";
    cout << "Test Case 3: Pattern not present\n";
    cout << "Result: " << findFirstOccurrence(text, pattern) << endl;
}

// Test Case 4: Empty pattern
void testCase4() {
    string text = "this is an empty pattern";
    string pattern = "";
    cout << "Test Case 4: Empty pattern\n";
    cout << "Result: " << findFirstOccurrence(text, pattern) << endl;
}
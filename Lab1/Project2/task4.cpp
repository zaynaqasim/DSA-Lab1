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


int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    return 0;
}

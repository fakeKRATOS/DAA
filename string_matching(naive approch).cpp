#include <iostream>
#include <string>
using namespace std;

// Function to perform naive string matching
void naiveStringMatch(string text, string pattern) {
    int n = text.length();    // Length of the text
    int m = pattern.length(); // Length of the pattern

    // Loop through all possible starting positions in the text
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check if pattern matches at current position i
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, exit inner loop
            }
        }

        // If j equals m, all characters matched
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    // Example usage
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Searching for pattern...\n";

    naiveStringMatch(text, pattern);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

// Function to perform Rabin-Karp string matching
void rabinKarpMatch(string text, string pattern, int prime) {
    int n = text.length();
    int m = pattern.length();
    if (m > n) return; // If pattern is longer than text, no match is possible

    long long p = 0; // Hash value for the pattern
    long long t = 0; // Hash value for the current window of text
    long long h = 1; // Hash factor for rolling hash

    const int d = 256; // Number of characters in the input alphabet (ASCII)

    // Calculate h = d^(m-1) % prime for rolling hash
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % prime;
    }

    // Calculate initial hash values for pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check if hash values match
        if (p == t) {
            bool match = true;
            // Verify character by character to confirm the match
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for the next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % prime;
            // Ensure t is non-negative
            if (t < 0) t += prime;
        }
    }
}

int main() {
    // Example usage
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    int prime = 101; // A small prime number for modulus

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Searching for pattern using Rabin-Karp...\n";

    rabinKarpMatch(text, pattern, prime);

    return 0;
}

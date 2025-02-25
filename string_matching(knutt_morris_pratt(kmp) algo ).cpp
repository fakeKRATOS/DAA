#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compute the LPS (Longest Proper Prefix which is also a Suffix) array
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); // Initialize LPS array with 0s
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // Fallback to the previous LPS value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to perform the Knuth-Morris-Pratt (KMP) string matching
vector<int> kmpMatcher(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern);  // Precompute the LPS array

    vector<int> occurrences;  // Store the indices of occurrences
    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {  // Pattern found
            occurrences.push_back(i - m);
            j = lps[j - 1];  // Look for the next possible match (overlapping)
        }

        // Mismatch after j matches
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Use LPS to shift pattern
            } else {
                i++; // Move text index
            }
        }
    }
    return occurrences;
}


int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> occurrences = kmpMatcher(text, pattern);

    cout << "Occurrences of '" << pattern << "' in '" << text << "': ";
    for (int index : occurrences) {
        cout << index << " ";
    }
    cout << endl;

    text = "ABABABAB";
    pattern = "ABA";
    occurrences = kmpMatcher(text, pattern);

    cout << "Occurrences of '" << pattern << "' in '" << text << "': ";
    for (int index : occurrences) {
        cout << index << " ";
    }
    cout << endl;

    text = "AABAACAADAABAABA";
    pattern = "AABA";
    occurrences = kmpMatcher(text, pattern);

    cout << "Occurrences of '" << pattern << "' in '" << text << "': ";
    for (int index : occurrences) {
        cout << index << " ";
    }
    cout << endl;


    return 0;
}

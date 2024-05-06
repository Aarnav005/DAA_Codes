#include <stdio.h>
#include <string.h>

#define d 256  // Base for the hash function (assuming ASCII characters)
#define q 101  // A prime number for modulo operations

void rabinKarp(char *pattern, char *text) {
    int m = strlen(pattern);
    int n = strlen(text);
    int hashP = 0, hashT = 0, h = 1;
    int found = 0; // Variable to track if at least one match is found

    // Precompute the value of d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Initialize hash values for the pattern and the first m characters of the text
    for (int i = 0; i < m; i++) {
        hashP = (d * hashP + pattern[i]) % q;
        hashT = (d * hashT + text[i]) % q;
    }

    // Main loop to slide the pattern over the text
    for (int i = 0; i <= n - m; i++) {
        // Check if the hash values match
        if (hashP == hashT) {
            // Check if the pattern matches the substring of the text
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m) {
                printf("Pattern found at index %d\n", i);
                found = 1; // Set found to true
            }
        }

        // Compute the new hash value for the next substring using the rolling hash function
        if (i < n - m) {
            hashT = (d * (hashT - text[i] * h) + text[i + m]) % q;
            if (hashT < 0)
                hashT += q;
        }
    }

    if (!found)
        printf("Pattern not found in the text.\n");
}

int main() {
    char pattern[] = "abc";
    char text[] = "abcxyzabcdabxabcdabcy";

    rabinKarp(pattern, text); // Call the modified function

    return 0;
}
#include <stdio.h>
#include <string.h>

#define d 256  // Base for the hash function (assuming ASCII characters)
#define q 101  // A prime number for modulo operations

int rabinKarp(char *pattern, char *text) {
    int m = strlen(pattern);
    int n = strlen(text);
    int hashP = 0, hashT = 0, h = 1;

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
            if (j == m)
                return i;  // Pattern found
        }

        // Compute the new hash value for the next substring using the rolling hash function
        if (i < n - m) {
            hashT = (d * (hashT - text[i] * h) + text[i + m]) % q;
            if (hashT < 0)
                hashT += q;
        }
    }

    return -1;  // Pattern not found
}

int main() {
    char pattern[] = "abc";
    char text[] = "abcxyzabcdabxabcdabcy";

    int index = rabinKarp(pattern, text);
    if (index == -1)
        printf("Pattern not found in the text.\n");
    else
        printf("Pattern found at index %d in the text.\n", index);

    return 0;
}
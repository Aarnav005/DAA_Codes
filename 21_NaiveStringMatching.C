#include <stdio.h>
#include <string.h>

// Function to perform naive string matching
void naiveStringMatch(char *text, char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        // Check if the current substring of text matches the pattern
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j])
                break; // Mismatch found, break the loop
        }

        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";
    
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    
    printf("Matching positions:\n");
    naiveStringMatch(text, pattern);

    return 0;
}

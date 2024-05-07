
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#define d 256

int hashToDigit(long long int hash, int q)
{
    return hash % q;
}

void search(char *pattern, char *text, int q)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int spuriousHits = 0;
    int patternCount = 0;
    for (i = 0; i < M - 1; i++)
	h = (h * d) % q;
    for (i = 0; i < M; i++)
    {
	p = (d * p + pattern[i]) % q;
	t = (d * t + text[i]) % q;
    }
    for (i = 0; i <= N - M; i++)
    {
	if (p == t)
	{
	    for (j = 0; j < M; j++)
	    {
		if (text[i + j] != pattern[j])
		    break;
	    }
	    if (j == M)
	    {
		printf("Pattern found at index %d\n", i); patternCount++;
	    }
	    else
	    {
		printf("Spurious hit at index %d\n", i); spuriousHits++;
	    }
	}

	if (i < N - M)
	{
	    t = (d * (t - text[i] * h) + text[i + M]) % q;
	    if (t < 0)
		t = (t + q);
	}
    }
    printf("Number of spurious hits: %d\n", spuriousHits);
    printf("Number of pattern occurrences found: %d\n", patternCount);
}

int main()
{
    char text[100];
    char pattern[100];
    int q;
    int patternHashDigit;
    clrscr();
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    printf("Enter the value of q: ");
    scanf("%d", &q);
    patternHashDigit = hashToDigit(123456789, q);
    printf("Hash value of pattern converted into digit: %d\n", patternHashDigit);
    search(pattern, text, q);
    getch();
    return(0);
}

#include<stdio.h>

// Function to find maximum and minimum elements in an array
int max, min;
int a[100]; // Declaration of array a to hold the input numbers

void maxmin(int i, int j)
{
    int max1, min1, mid;
    if(i == j) // If only one element is present
    {
        max = min = a[i]; // Assign both max and min to the single element
    }
    else
    {
        if(i == j - 1) // If only two elements are present
        {
            if(a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else // If more than two elements are present
        {
            mid = (i + j) / 2; // Calculate the mid point
            maxmin(i, mid); // Recursively find max and min in the first half
            max1 = max; 
            min1 = min;
            maxmin(mid + 1, j); // Recursively find max and min in the second half
            if(max < max1) // Compare max of first half with max of second half
                max = max1;
            if(min > min1) // Compare min of first half with min of second half
                min = min1;
        }
    }
}

int main()
{
    int i, num;
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);

    printf("Enter the numbers : \n");
    for(i = 0; i < num; i++) // Corrected the loop starting index to 0
        scanf("%d", &a[i]);

    max = a[0]; // Initialize max with the first element of the array
    min = a[0]; // Initialize min with the first element of the array

    maxmin(0, num - 1); // Call the function to find max and min
    printf("Minimum element in the array : %d\n", min);
    printf("Maximum element in the array : %d\n", max);
    return 0;
}

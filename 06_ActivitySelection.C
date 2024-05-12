#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

int compare(const void* a, const void* b) {
    Activity* actA = (Activity*)a;
    Activity* actB = (Activity*)b;
    return actA->finish - actB->finish;
}

void activitySelection(Activity activities[], int n) {
    int j=0;
    int i;
    qsort(activities, n, sizeof(Activity), compare);
    printf("Selected activities:\n");
    printf("(%d, %d)\n", activities[j].start, activities[j].finish);
    for (i = 1; i < n; i++) {
        if (activities[i].start >= activities[j].finish) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            j = i;
        }
    }
}

void main() {
    int n,i;
    Activity* activities = (Activity*)malloc(n * sizeof(Activity));
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    printf("Enter the start and finish times of the activities:\n");
    for (i = 0; i < n; i++) {
	    scanf("%d %d", &activities[i].start, &activities[i].finish);
    }
    activitySelection(activities, n);
    getch();
}

/*
Alternate Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int length;
    printf("Enter the length: ");
    scanf("%d", &length);

    int *start = (int*) malloc (length * sizeof(int));
    int *finish = (int*) malloc (length * sizeof(int));

    if (start == NULL || finish == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter the start array: ");
    for(int i = 0 ; i < length ; i++) 
        scanf("%d", &start[i]);

    printf("\nEnter the finish array: ");
    for(int i = 0 ; i < length ; i++)
        scanf("%d", &finish[i]);

    for(int i = 0 ; i < length - 1 ; i++) {
        for(int j = 0 ; j < length - i - 1 ; j++) {
            if(finish[j] > finish[j+1]) {
                int temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
                
                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    printf("\n0 ");
    int j = 0, ctr = 0;
    for(int i = 1 ; i < length ; i++) {
        if(start[i] >= finish[j]) {
            printf("%d ", i);
            j = i;
        }
    }

    free(start);
    free(finish);

    return 0;
}

*/
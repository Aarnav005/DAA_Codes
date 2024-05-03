#include <stdio.h>
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
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected activities:\n");
    int j = 0;
    printf("(%d, %d)\n", activities[j].start, activities[j].finish);

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[j].finish) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            j = i;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity* activities = (Activity*)malloc(n * sizeof(Activity));

    printf("Enter the start and finish times of the activities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    activitySelection(activities, n);
    free(activities);
    return 0;
}
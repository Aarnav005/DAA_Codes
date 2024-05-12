#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct {
    int id;         // Job ID
    int profit;     // Profit from the job
    int deadline;   // Deadline of the job
} Job;

// Function to compare jobs based on profit (used in qsort)
int compare_jobs(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Function to find the maximum deadline among all jobs
int max_deadline(Job* jobs, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

// Function to schedule jobs with deadlines
void schedule_with_deadline(Job* jobs, int n) {
    // Sort jobs based on profit in non-decreasing order
    qsort(jobs, n, sizeof(Job), compare_jobs);
    
    // Find the maximum deadline among all jobs
    int max_dl = max_deadline(jobs, n);

    // Array to store the scheduled jobs
    int* schedule = (int*)malloc((max_dl + 1) * sizeof(int));
    for (int i = 0; i <= max_dl; i++) {
        schedule[i] = -1; // Initialize schedule with -1 (empty slot)
    }

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                break;
            }
        }
    }

    // Print the schedule
    printf("Optimal schedule J: ");
    for (int i = 1; i <= max_dl; i++) {
        if (schedule[i] != -1) {
            printf("%d ", schedule[i]);
        }
    }
    printf("\n");

    // Free dynamically allocated memory
    free(schedule);
}

int main() {
    // Example: Jobs {id, profit, deadline}
    Job jobs[] = {{1, 35, 3}, {2, 30, 4}, {3, 25, 4}, {4, 20, 2}, {5, 15, 3}, {6, 12, 1}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Schedule jobs
    schedule_with_deadline(jobs, n);

    return 0;
}

/*
Alternate Code

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_schedule(int *schedule, int jobs) {
    for(int i=0 ; i<jobs ; i++) {
        if(schedule[i] != -1)
            printf("J%d -> ", schedule[i]);
    }
}

void job_sequencing(int *deadline, int *index, int jobs) {
    int *schedule = (int *) malloc (jobs * sizeof(int));

    for(int i=0 ; i<jobs ; i++) 
        schedule[i] = -1;

    for(int i=0 ; i<jobs ; i++) {
        bool set = false;
        int j = deadline[i];
        while(j > 0 && schedule[j] != -1) {
            j--;
        }
        if(j > 0) {
            schedule[j] = index[i];
        }
    }

    print_schedule(schedule, jobs);

    free(schedule);
}

int main() {
    int jobs, temp;

    printf("Enter the number of jobs: ");
    scanf("%d", &jobs);

    int *deadline = (int *) malloc (jobs * sizeof(int));
    int *profit = (int *) malloc (jobs * sizeof(int));
    int *index = (int *) malloc (jobs * sizeof(int));

    for(int i=0 ; i<jobs ; i++) {
        printf("Enter deadline and profit for J%d: ", i+1);
        scanf("%d %d", &deadline[i], &profit[i]);
        index[i] = i+1;
    }

    for(int i=0 ; i<jobs ; i++) {
        for(int j=0 ; j<jobs-i-1 ; j++) {
            if(profit[j] < profit[j+1]) {
                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = temp;

                temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    }

    job_sequencing(deadline, index, jobs);

    free(profit);
    free(deadline);
    free(index);

    return 0;
}
*/
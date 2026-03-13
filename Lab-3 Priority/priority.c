#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, choice;
    int at[20], bt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int rt[20];
    int visited[20] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    printf("\n1. Non-Preemptive Priority\n");
    printf("2. Preemptive Priority\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
        while(completed < n) {
            int idx = -1;
            int high = 999;

            for(i = 0; i < n; i++) {
                if(at[i] <= time && visited[i] == 0) {
                    if(pr[i] < high) {
                        high = pr[i];
                        idx = i;
                    }
                }
            }

            if(idx != -1) {
                time += bt[idx];
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                visited[idx] = 1;
                completed++;
            } else {
                time++;
            }
        }
        break;

        case 2:
        while(completed < n) {
            int idx = -1;
            int high = 999;

            for(i = 0; i < n; i++) {
                if(at[i] <= time && rt[i] > 0) {
                    if(pr[i] < high) {
                        high = pr[i];
                        idx = i;
                    }
                }
            }

            if(idx != -1) {
                rt[idx]--;
                time++;

                if(rt[idx] == 0) {
                    ct[idx] = time;
                    tat[idx] = ct[idx] - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                    completed++;
                }
            } else {
                time++;
            }
        }
        break;

        default:
        printf("Invalid choice");
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

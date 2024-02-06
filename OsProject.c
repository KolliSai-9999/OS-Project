#include<stdio.h> 
int main() {
    int i, j, p, n, x, q, total = 0, count = 0, wt = 0, tt = 0, at[100], bt[100], temp[100], sum = 0; 
    float avg_wt, avg_tt;
    
    printf("Queries are taken only from 10am to 12am. Enter time as minutes from 0 to 120\n");
    printf("For example enter 10:30am as 30 and 11:30am as 90 etc\n");
    printf("Enter no. of processes: "); 
    scanf("%d", &n);
    x = n; 
    
    for (i = 0; i < n; i++) {
        printf("Enter 1 for faculty and 2 for student: ");
        scanf("%d", &p); 
        printf("Process: %d\n", i + 1);
        printf("Enter arrival time: "); 
        scanf("%d", &at[i]);
        printf("Enter burst time: "); 
        scanf("%d", &bt[i]); 
        temp[i] = bt[i];
    }

    printf("\nEnter quantum: "); 
    scanf("%d", &q);
    printf("\nProcess ID Burst time Turnaround time Waiting time\n"); 
    
    for (total = 0, i = 0; x != 0;) {
        if (temp[i] <= q && temp[i] > 0) {
            total += temp[i]; 
            temp[i] = 0; 
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] -= q;
            total += q;
        }

        if (temp[i] == 0 && count == 1) {
            x--;
            printf("Process-%d\t %d\t\t%d\t\t %d\n", i + 1, bt[i], total - at[i], total - at[i] - bt[i]); 
            wt += total - at[i] - bt[i];
            tt += total - at[i]; 
            count = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= total) {
            i++;
        } else {
            i = 0;
        }
    }

    for (j = 0; j < n; j++) {
        sum += bt[j];
    }

    avg_wt = (float)wt / n; 
    avg_tt = (float)tt / n;
    
    printf("\nAverage waiting time: %f\n", avg_wt); 
    printf("Average turnaround time: %f\n", avg_tt); 
    printf("Total time spent: %d\n", sum);
    
    return 0;
}

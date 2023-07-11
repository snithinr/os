#include<stdio.h>

struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int turnaround_time;
    int waiting_time;
};

void priorityScheduling(struct process p[], int n) {
    int i, j, time = 0, sum_bt = 0;
    float average_wait_time = 0, average_turnaround_time = 0;
    struct process temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        sum_bt += p[i].burst_time;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");

    for(i = 0; i < sum_bt; ) {
        int highest_priority = -9999, pos;

        for(j = 0; j < n; j++) {
            if(p[j].arrival_time <= time && p[j].priority > highest_priority && p[j].burst_time > 0) {
                highest_priority = p[j].priority;
                pos = j;
            }
        }

        i += p[pos].burst_time;
        time += p[pos].burst_time;

        p[pos].turnaround_time = time - p[pos].arrival_time;
        p[pos].waiting_time = p[pos].turnaround_time - p[pos].burst_time;

        average_wait_time += p[pos].waiting_time;
        average_turnaround_time += p[pos].turnaround_time;

        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[pos].process_id, p[pos].arrival_time, p[pos].burst_time, p[pos].priority, p[pos].waiting_time, p[pos].turnaround_time);

        p[pos].burst_time = 0;
    }

    printf("\n\nAverage waiting time = %f", (average_wait_time / n));
    printf("\nAverage turnaround time = %f", (average_turnaround_time / n));
}

int main() {
    int n, i;
    struct process p[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter the arrival time, burst time and priority of process %d: ", i + 1);
        scanf("%d%d%d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].process_id = i + 1;
    }

    priorityScheduling(p, n);

    return 0;
}

#include <stdio.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct process processes[MAX_PROCESSES];
    int n, quantum, i, total_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        total_time += processes[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("\nGantt chart:\n");

    int current_time = 0, completed = 0;
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                printf("| P%d ", processes[i].pid);
                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    completed++;
                }
            }
        }
        if (completed == n) break;
        if (current_time >= total_time) break;
        current_time++;
    }
    printf("|\n");

    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("\nProcess\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);

    return 0;
}
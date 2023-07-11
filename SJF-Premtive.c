#include <stdio.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    struct process processes[MAX_PROCESSES], temp;
    int n, i, j, total_waiting_time = 0, total_turnaround_time = 0, completed_processes = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int current_time = processes[0].arrival_time, shortest_job_index;
    while (completed_processes < n) {
        shortest_job_index = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_job_index == -1 || processes[i].remaining_time < processes[shortest_job_index].remaining_time) {
                    shortest_job_index = i;
                }
            }
        }
        if (shortest_job_index == -1) {
            current_time = processes[completed_processes].arrival_time;
        } else {
            processes[shortest_job_index].remaining_time--;
            if (processes[shortest_job_index].remaining_time == 0) {
                completed_processes++;
                processes[shortest_job_index].waiting_time = current_time - processes[shortest_job_index].arrival_time - processes[shortest_job_index].burst_time + 1;
                processes[shortest_job_index].turnaround_time = processes[shortest_job_index].waiting_time + processes[shortest_job_index].burst_time;
                total_waiting_time += processes[shortest_job_index].waiting_time;
                total_turnaround_time += processes[shortest_job_index].turnaround_time;
            }
            current_time++;
        }
    }

    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;
    printf("\nProcess\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time,processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);
    return 0;
}

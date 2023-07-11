#include<stdio.h>

struct process
{
    int no,bt,tat,wt,pri;
};

int main(){
    int n;
    printf("Enter no of processes : ");
    scanf(" %d",&n);
    
    struct process procArr[n]; 
    for (int i=0;i<n;i++){
        printf("Enter burst time of process %d : ",i+1);
        scanf(" %d",&procArr[i].bt);
        printf("Enter priority of process %d : ",i+1);
        scanf(" %d",&procArr[i].pri);
        procArr[i].no = i;
    }

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if(procArr[i].pri < procArr[j].pri){
                struct process temp = procArr[i];
                procArr[i] = procArr[j];
                procArr[j] = temp;
            }
        }
    }
    float total_waiting_time = 0,total_turnaround_time = 0;
    for (int i=0;i<n;i++){
        int tat = 0;
        int wt = 0;
        for (int j=0;j<i;j++){
            wt += procArr[j].bt;
            tat += procArr[j].bt;
        }
        tat += procArr[i].bt;
        procArr[i].wt = wt;
        procArr[i].tat = tat;
        total_turnaround_time += tat;
        total_waiting_time += wt;
    }
    printf("Pid\t|\tBT\t|\tPri\t|\tWT\t|\tTAT\t|\n");
    for (int i=0;i<n;i++){
        printf("P%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",procArr[i].no,procArr[i].bt,procArr[i].pri,procArr[i].wt,procArr[i].tat);
    }    

    printf("Average waiting time : %f\nAverage Turnaround time : %f\n",total_waiting_time/n,total_turnaround_time/n);
    return 0;
}
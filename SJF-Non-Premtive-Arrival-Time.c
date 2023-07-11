#include<stdio.h>

int main(){
    int n;
    printf("enter the number of proccess ; " );
    scanf("%d",&n);
    int at[n+1],sum_burst_time=0,burst_time[n+1],time,smallest;
    for(int i = 0 ; i < n ; i++){
        printf("the arrival time for process P%d : ", i + 1);
        scanf("%d", & at[i]);
        printf("the burst time for process P%d : ", i + 1);
        scanf("%d", & burst_time[i]);
        sum_burst_time += burst_time[i];
    }
    burst_time[n] = 99999;
    printf("|\tProcess\t|Turnaround\t|\tWaiting\t|\n");
    for(time =0 ;time < sum_burst_time;){
        smallest = n;
        for(int i=0;i<n;i++){
            if(at[i] <= time && burst_time[i] >0 && burst_time[i] < burst_time[smallest])
                smallest = i;
        }
        printf("|\tP%d\t|\t%d\t|\t%d\t|\n",smallest+1,time + burst_time[smallest] - at[smallest],time-at[smallest]);
        time+=burst_time[smallest];
        burst_time[smallest] = 0;
    }
    return 0;
}
    
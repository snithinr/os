#include<stdio.h>

void sort(int * BurstTime,int * Process, int size){
	for(int i=0;i<size;i++){
			for(int j=i+1;j<size;j++){
				if(BurstTime[i]>BurstTime[j]){
					int temp1 = BurstTime[j];
					BurstTime[j] = BurstTime[i];
					BurstTime[i] = temp1;
					int temp2 = Process[j];
					Process[j] = Process[i];
					Process[i] = temp2;
				}
			}
	}	
}

void display(int *BurstTime,int *Process,int size){
        printf("Processid	BurstTime	turnarroundTime		waitingTime\n");
        for(int i=0;i<size;i++){
				int turnarrTime = 0;
				int waitingTime = 0; 
				for(int j=0 ;j < i ;j ++){
					waitingTime += BurstTime[j];
				}
				for(int k=0;k<= i ;k++){
					turnarrTime += BurstTime[k];
				}
                printf("%d   %d    %d    %d\n",Process[i],BurstTime[i],turnarrTime,waitingTime);
        }
        printf("\n");
}

float waitingTime(int *BurstTime,int size){
	float avgWaitingTime = 0;
	for(int i=0;i<size-1;i++){
		avgWaitingTime += BurstTime[i];
	}
	return (avgWaitingTime/size);
}

float turnAroundTime(int * BurstTime,int size){
	float avgTurnAroundTime = 0;
	for (int i = 0; i < size; i++){
		avgTurnAroundTime += BurstTime[i];
	}
	return (avgTurnAroundTime/size);
}


int main(){
	printf("Enter the no of processes : ");
	int n;
	scanf("%d",&n);
	int BurstTime[n];
	int Process[n];
	for(int i=1;i<=n;i++){
		printf("Enter process id : ");
		scanf("%d",&Process[i-1]);
		printf("Enter burst time of process(%d) : ",Process[i-1]);
		scanf("%d",&BurstTime[i-1]);	
	}
	sort(BurstTime,Process,n);
	display(BurstTime,Process,n);

	printf("\n\nAverage Waiting Time : %f",waitingTime(BurstTime,n));
	printf("\n\nAverage Turn Around Time : %f",turnAroundTime(BurstTime,n));
}

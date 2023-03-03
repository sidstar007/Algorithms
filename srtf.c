#include <stdio.h>

int n;

//Shortest Remaining Time First Scheduling
void srft(int process[][2]) {
	int time=0,smallest=0,complete=0;
	int processCTWT[n][2]; //2D array to store completion time and waiting time
	
	int burstTime[n]; //Array to store burst time
	
	for (int i=0;i<n;++i) {
		burstTime[i]=process[i][1]; //Storing burst time
	}
	
	while (complete<n) {
		for (int i=0;i<n;++i) {
			if (process[i][0]<=time && process[i][0]!=-1 && process[i][1]<process[smallest][1]) { //Checking the current shortest burst time
				smallest=i;
			}
		}
		
		process[smallest][1]--;
		time++;
		
		if (process[smallest][1]==0) {
			complete++;
			processCTWT[smallest][0]=time;
			processCTWT[smallest][1]=processCTWT[smallest][0]-process[smallest][0]-burstTime[smallest]; //Waiting time = (Turn Around Time) - (Burst Time)
			process[smallest][0]=-1; //Making PID = -1 to indicate process completion
			process[smallest][1]=9999; //Making burst time to maximum, so that all other burst times are smaller than it (Assuming no burst is greater than 9999)
		}
	}
	
	printf("PID\tComplete Time\tWaiting Time\n"); //Printing Completion Time and Waiting Time for each process
	for (int i=0;i<n;++i) {
		printf("%d\t%d\t%d\n",i+1,processCTWT[i][0],processCTWT[i][1]);
	}
}
			
	

int main() {
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	
	int process[n][2];
	
	for (int i=0;i<n;++i) {
		printf("Enter arrival time of process %d: ",i+1);
		scanf("%d",&process[i][0]);
		printf("Enter burst time of process %d: ",i+1);
		scanf("%d",&process[i][1]);
	}
	
	srft(process);
	
	return 0;
}

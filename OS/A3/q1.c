#include<stdio.h>
#include<stdlib.h>

typedef struct  {
int arrival[2];
int burst[2];
int priority;
int remaining[2];
}Process;

int main(){
        int n;

        printf("Enter the number of processes: ");
        scanf("%d",&n);

        Process *processes = (Process *)malloc(n*sizeof(Process));
        if(processes==NULL) {
        printf("Memory allocation failed.\n");
        return 1;
        }

        for(int i=0;i<n;i++){

		printf("Enter priority for P%d:",i);
		scanf("%d",&processes[i].priority);	

                for(int j=0;j<2;j++){
                	printf("Enter arrival time for P%d instance %d: ",i,j+1);
                	scanf("%d",&processes[i].arrival[j]);
                	printf("Enter burst time for p%d instance %d: ",i,j+1);
                	scanf("%d",&processes[i].burst[j]);

			processes[i].remaining[j] = processes[i].burst[j];
                }
        }
	
	int current_time = 0;
        int finished = 0;
        int executed[n][2];
        int completion_time[n][2];
        int turnaround_time[n];
        int waiting_time[n];

        for(int i=0;i<n;i++){
                for(int j=0;j<2;j++){
                        executed[i][j] = 0;
                        completion_time[i][j] = 0;
                }
                turnaround_time[i] = 0;
                waiting_time[i] = 0;
        }

	printf("\nGantt chart:\n");
	printf("Start time\t process\t finish time\n");

	while(finished < n*2){
		int selected_process = -1;
		int selected_instance = -1;
		int min_priority = 1e9;

		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				if(!executed[i][j] && processes[i].arrival[j] <= current_time){
					if(processes[i].priority < min_priority ||(processes[i].priority == min_priority && processes[i].arrival[j] < processes[selected_process].arrival[selected_instance])){
						min_priority = processes[i].priority;
						selected_process = i;
						selected_instance = j;
					}
				}
			}
		}

		if(selected_process == -1){
			current_time++;
			continue;	
		}

		printf("%d\t\tP%d\t\t%d\n",current_time,selected_process,current_time+1);
		processes[selected_process].remaining[selected_instance]--;
		current_time++;

		if(processes[selected_process].remaining[selected_instance]==0){
			executed[selected_process][selected_instance] = 1;
			completion_time[selected_process][selected_instance] = current_time;
			finished++;
		}
	}

	for(int i=0;i<n;i++){
		int max_completion_time = -1;
		int total_burst_time = 0;

		for(int j=0;j<2;j++){
			if(completion_time[i][j] > max_completion_time){
				max_completion_time = completion_time[i][j];
			}
			total_burst_time += processes[i].burst[j];
		}

		turnaround_time[i] = max_completion_time - processes[i].arrival[0];
		waiting_time[i] = turnaround_time[i] - total_burst_time;
	}
	
	printf("\nProcess\tTat\tWT\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\n",i,turnaround_time[i],(waiting_time[i]-2));
	}

	float total_tat = 0, total_wt = 0;
	for(int i = 0;i<n;i++){
		total_tat += turnaround_time[i];
		total_wt += waiting_time[i];
	}

	printf("\nAverage Turnaround Time:%.2f\n",total_tat/n);
	printf("Average Waiting Time:%.2f\n",(total_wt/n)-2);

	free(processes);
	return 0;

}



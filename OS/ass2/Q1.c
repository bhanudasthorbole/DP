#include<stdio.h>
#include<stdlib.h>

typedef struct  {
int arrival[2];
int burst[2];
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
	int current_time = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
		printf("Enter arrival time for P%d instance %d: ",i,j+1);
		scanf("%d",&processes[i].arrival[j]);
		printf("Enter burst time for p%d instance %d: ",i,j+1);
		scanf("%d",&processes[i].burst[j]);
		}
	}

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
/*
	printf("\nGant Chart:\n");
	printf("Start Time\tProcess(ID)\tFinish Time\n");

	while(finished < n*2 ){
		int selected_process =-1;
		int selected_instance = -1;
		int min_burst_time = 1e9;
		int min_arrival_time = 1e9;

		for(int i = 0;i<n;i++){
			for(int j=0;j<2;j++){
				if(!executed[i][j] && processes[i].arrival[j] <= current_time) {
					if(processes[i].burst[j] < min_burst_time || (processes[i].burst[j]==min_burst_time && processes[i].arrival[j] < min_arrival_time)){
						min_burst_time = processes[i].burst[j];
						min_arrival_time = processes[i].arrival[j];
						selected_process = i;
						selected_instance = j;
					}
				}
			}
		}

		if(selected_process == -1){
			for(int i=0;i<n;i++){
				for(int j=0;j<2;j++){
					if(!executed[i][j] && processes[i].arrival[j] < min_arrival_time) {
						min_arrival_time = processes[i].arrival[j];
						selected_process = i;
						selected_instance = j;
					}
				}
			}
			current_time = min_arrival_time;
		}

		int start_time = current_time;
		int finish_time = current_time + processes[selected_process].burst[selected_instance];

		completion_time[selected_process][selected_instance] = finish_time;

		printf("%d\t\tP%d\t\t%d\n",start_time,selected_process,finish_time);

		current_time = finish_time;
		executed[selected_process][selected_instance] = 1;
		finished++;
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
	}*/

        int completed=0;
	printf("\n______________________ Gantt Chart ________________________\n");
    printf("|");
              
    while (completed != n) {
        int i = find_next_process(processes, n, current_time);

        if (i != -1) {
            current_time = (current_time < processes[i]->arrival) ? processes[i]->arrival : current_time;
            processes[i].completion = current_time + processes[i].burst;
            processes[i].turnaround = processes[i].completion - processes[i].arrival;
            processes[i].waiting = processes[i].turnaround - processes[i].burst;
            processes[i].is_completed = 1;
            completed++;

            total_turnaround += processes[i].turnaround;
            total_waiting += processes[i].waiting;

            // Gantt Chart display
            printf("  P%d  |", processes[i].pid);
            current_time += processes[i].burst;
        } else {
            current_time++;
        }
    }

    // Gantt Chart timeline
    printf("\n0");
    for (int i = 0; i < n; i++) {
        printf("     %d", processes[i].completion);
    }


	printf("\nProcesses\tTAT\tWT\n");
	for(int i = 0;i<n;i++){
		printf("P%d\t\t%d\t%d\n",i,turnaround_time[i],(waiting_time[i]-2));
	}

	float total_tat = 0,total_wt = 0;
	for(int i = 0;i<n;i++){
		total_tat += turnaround_time[i];
		total_wt += waiting_time[i];
	}

	printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
	printf("\nAverage Waiting Time: %.2f\n", (total_wt / n) - 2);

	free(processes);

	return 0;
}

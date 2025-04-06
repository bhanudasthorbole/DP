#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>

struct Process {    
	int process_no;  
    	int Arrival_time;
    	int burst_time;
    	int start_time;
    	int finish_time;
};

int compareByArrivalTime(const void *a, const void *b) 
{
    	struct Process *structA = (struct Process *)a;
    	struct Process *structB = (struct Process *)b;
    	return (structA->Arrival_time - structB->Arrival_time);
}
int countDistinctProcesses(struct Process process[], int n)
{
    	int count=0;
	int hash_set[1000] = {0};  
	for (int i = 0; i < n; i++) 
	{ 
    		int process_no =process[i].process_no;
    		if (hash_set[process_no] == 0) 
     		{ 
			hash_set[process_no] = 1; 
			count++; 
    		}
	}
	return count;
	
}
int main() {
    	int n,i,j,k,temp_arrival;
    	int wt_sum=0,tat_sum=0;
    	printf("\nEnter No of Processes:- ");
    	scanf("%d",&n);
	struct Process process[n];
	
	for(i=0;i<n;i++)
	{
process:		printf("\nEnter Process No:- ");
			scanf("%d",&process[i].process_no);
			if(process[i].process_no <0)
			{	
				goto process;
			}
arrival:		printf("\nFor Process P%d , Enter Arrival Time:- ",process[i].process_no);
			scanf("%d",&process[i].Arrival_time);
			if(process[i].Arrival_time < 0)
			{
				goto arrival;
			}
cpu_burst:		printf("\nFor Process P%d , Enter CPU Burst Time:- ",process[i].process_no);
			scanf("%d",&process[i].burst_time);
			if(process[i].burst_time <=0  )
			{
				goto cpu_burst;
			}
			process[i].start_time=-1;
			process[i].finish_time=-1;	
	}
   	//struct Process process[] = { {2,5,3,-1,-1},{1,10,4,-1,-1},{3,14,2,-1,-1},{4,20,1,-1,-1},{2,0,3,-1,-1},{1,1,5,-1,-1},{3,2,4,-1,-1},{4,3,6,-1,-1}};
        qsort(process,(size_t) n, sizeof(struct Process), compareByArrivalTime);
   	for(i=0;i<n;i++)
   	{
   		if(process[i].Arrival_time==0)
   		{
   			process[i].start_time=0;
   		}
   		else{
   			process[i].start_time=process[i-1].start_time + process[i-1].burst_time;
   		}
   		if(process[i].Arrival_time==0)
   		{
   			process[i].finish_time=0 + process[i].burst_time;
   		}
   		else{
   			process[i].finish_time=process[i-1].finish_time + process[i].burst_time;
   		}
   	}
   	printf("\n______________________ Gantt Chart ________________________\n");
   	printf("\n");
   	for(i=0;i<n;i++)
   	{
   		//	printf("________");	       	
		printf("--------");     }
   	printf("-");
   	printf("\n");
   	for(i=0;i<n;i++)
   	{
   		printf("|  P%d   ",process[i].process_no);
   	}
   	printf("|");
   	printf("\n");
   	for(i=0;i<n;i++)
   	{
   		printf("--------");
   	}
   	printf("-");
   	printf("\n%d",process[0].start_time);
   	for(i=0;i<n;i++)
   	{
   		printf("\t%d",process[i].finish_time);
   	}
   	
   	int distinct_process_count = countDistinctProcesses(process,n);
   	int WT[distinct_process_count],TAT[distinct_process_count];;
   	for(i=0;i<distinct_process_count;i++)
    	{
		WT[i]=0;
		for(j=0;j<n;j++)
		{
	     		if(process[i].process_no==process[j].process_no)
		    		WT[i]+=(process[j].start_time - process[j].Arrival_time);
		}
		wt_sum+=WT[i];
	 	// printf("\nWT for P%d= %d",i,WT[i]);
		 }
		         for(i=0;i<=distinct_process_count;i++)
		             {
		                     for(j=n-1;j>=0;j--)
			     	     {
				 	     if(process[j].process_no==i)
				 	     {
				     		     for(k=0;k<n;k++)
				     		     {
					 		     if(process[k].process_no == i)
					 		     {
					     			     temp_arrival=process[k].Arrival_time;
					     			     break;
					 		     }
				     		     }
				     		     TAT[i]=process[j].finish_time - temp_arrival;
				      		     // printf("\nTAT for P%d= %d",i,TAT[i]);
						                      tat_sum+=TAT[i];                
								      break;
				 	     }
			     	     }
			     }
		     	 printf("\n\nP.no \tTAT\tWT\n");
		    	 
		     	 printf("---------------------\n");
		    	 for(i=1;i<=distinct_process_count;i++)
		    	 {
				 printf("P%d\t%d\t%d\n",i-1,TAT[i-1],WT[i-1]);
		    	 }
			 
			 
		     	 float wt_avg,tat_avg;
		     	 printf("\nWaiting time sum =%d\nTurn Around Time Sum=%d\n",wt_sum,tat_sum);
		     	 wt_avg=(float)wt_sum/(float)distinct_process_count;
		     	 tat_avg=(float)tat_sum/(float)distinct_process_count;
		     	 printf("\nAverage Waiting Time:- %f\nAverage Turn Around Time:- %f\n",wt_avg,tat_avg);
			 
		     	 return 0;
			 
}

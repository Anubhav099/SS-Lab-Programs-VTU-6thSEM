#include<stdio.h>
int main()
{
	int n, ch, remain;
	int at[10],bt[10],rt[10];
	
	printf("1.Round Robin\n2.SRTF\nEnter your choice: ");
	scanf("%d",&ch);
	
	printf("\nEnter no of Processes : ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("Enter arrival time for Process P%d : ",i+1);
		scanf("%d",&at[i]);
		printf("Enter burst time for Process P%d :",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	
	switch(ch)
	{
	  case 1:
	   	int flag=0, time=0, time_quantum, sum_waittime=0,sum_turnaround=0;
	   	remain = n;
	   	
		printf("Enter Time Quantum: ");
		scanf("%d",&time_quantum);
		printf("\nProcess | Turnaround Time | Waiting Time\n");
		
		for(int count=0; remain != 0;)
		{
			if(rt[count]<=time_quantum && rt[count]>0)
			{
				time += rt[count];
				rt[count]=0;
				flag=1;
			}
			else if(rt[count]>0)
			{
				rt[count] -= time_quantum;
				time += time_quantum;
			}
			if(rt[count]==0 && flag==1)
			{
				flag=0;
				remain--;
				printf("P[%d]\t|\t%d\t|\t%d\n", (count+1) , (time-at[count]) , (time-at[count]-bt[count]) );
				
				sum_waittime += (time-at[count]-bt[count]) ;
				sum_turnaround += (time-at[count]) ;
			}
			if(count==n-1)
				count=0;
			else if(at[count+1]<=time)
				count++; 
			else	count=0;
		}
		
		printf("\nAverage Waiting Time= %.2f\n", sum_waittime*1.0/n);
		printf("Avg Turnaround Time= %.2f\n", sum_turnaround*1.0/n);
		break;
	  case 2:
	   	int sum_wt=0,sum_tt=0,endTime,smallest;
		remain = n;
		
		printf("\nProcess | Turnaround Time | Waiting Time\n");
		
		rt[9]=9999;
		for(int time=0; remain!=0; time++)
		{
			smallest=9;
			for(int i=0;i<n;i++)
				if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
					smallest = i;
			
			rt[smallest]--;
			if(rt[smallest]==0)
			{
				remain--;
				endTime = time+1;
				printf("P[%d]\t|\t%d\t|\t%d\n", (smallest+1) , (endTime-at[smallest]) , (endTime-at[smallest]-bt[smallest]) );
				
				sum_wt += (endTime-bt[smallest]-at[smallest]) ;
				sum_tt += (endTime-at[smallest]) ;
			}
		}
		
		printf("\nAverage waiting time = %.2f\n", sum_wt*1.0/n);
		printf("Average Turnaround time= %.2f\n", sum_tt*1.0/n);
		break;
	default:
		printf("Invalid option!\n");
	}
	return 0;
}


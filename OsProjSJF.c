#include<stdio.h>
# define max 30

void main()
{
	int i,j,n,t,p[max],bt[max],wt[max],ct[max],tat[max];
	float awt=0,atat=0;
	
	scan:
	system("cls");
	system("COLOR B0");
	printf("\n               **SHORTEST JOB FIRST ALGORITHM (NON-PRIMITIVE)**\n");
    printf("\t\t==============================================\n\n");
	printf("\nEnte r the no of Process you want to Execute: ");
	scanf("%d",&n);
	
	
	printf("\nEnter the Burst Time for each Process: \n");
	for(i=0;;)
	{
		printf("P%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
		if(bt[i]<10)
		{
           i++;
		}
		else
		{
		   printf("Burst Time should be less than 10\n");
		}
	    if(i==n)
		{
		break;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(bt[j]>bt[j+1])
			{
				  t=bt[j];
				  bt[j]=bt[j+1];
				  bt[j+1]=t;
				  
				  t=p[j];
				  p[j]=p[j+1];
				  p[j+1]=t;
		   }
		
		}
		
	
	}
	printf("\nProcess \t Burst_time \t Comp_time \t Wait_time \t Turn_A_time");
    wt[0]=3;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]=wt[i]+bt[j];
		}
		awt=awt+wt[i];
	}
	for(i=0;i<n;i++)
	{
		ct[i]=bt[i]+wt[i];
	}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-wt[i];
		printf("\nP%d\t\t %d\t\t %d\t\t %d\t\t\t %d",p[i],bt[i],ct[i],wt[i],tat[i]);
		atat=atat+tat[i];
	}
	awt=awt/n;
	atat=atat/n;
	printf("\n\nAverage Wait_time:%f\n",awt);
	printf("\nAverage Turn_A_time:%f\n",atat);
	getch();
}

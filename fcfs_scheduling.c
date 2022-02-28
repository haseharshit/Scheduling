#include<stdio.h>
#include<string.h>
int main()
{
    int pn[10];
    int ar[10],burst[10],start[10],finish[10],tat[10],wt[10],i,j,n,temp;
    int totwt=0,tottat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
       printf("\nEnter the Process_no.: ");
       scanf("%d",&pn[i]);
       printf("\nEnter Arrival time: ");
       scanf("%d",&ar[i]);
       printf("\nEnter Burst time: ");
       scanf("%d",&burst[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ar[i]>ar[j])
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
               // strcpy(t,pn[i]);
               // strcpy(pn[i],pn[j]);
               // strcpy(pn[j],t);
               temp=pn[i];
               pn[i]=pn[j];
               pn[j]=temp;
            }

        }
    }
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            start[i]=ar[i];
        }
        else{
            start[i]=finish[i-1];
        }

        wt[i]=start[i]-ar[i];
        finish[i]=start[i]+burst[i];
        tat[i]=finish[i]-ar[i];
    }
    printf("\nPid Arrtime Burtime WaitTime Start TAT Finish");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d",pn[i],ar[i],burst[i],wt[i],start[i],tat[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\nAverage Waiting time:%f",(float)totwt/n);
    printf("\nAverage Turn Around Time:%f",(float)tottat/n);
    return 0;
}

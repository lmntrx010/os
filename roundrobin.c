#include<stdio.h>


int main()
{
    int n,i,j,ts;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int bt[n],at[n],tat[n],wt[n],rt[n],ct[n];
    int ttat=0,twt=0;
    printf("arrival time and burst time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",at[i],bt[i]);
    }
    printf("Enter time quantum");
    scanf("%d",&ts);
    int flag;
    int time=0;i=0;
    int remain=n;
    while(remain!=0)
    {
        if(rt[i]<=ts && rt[i]>0)
        {
            time+=rt[i];
            rt[i]=0;
            flag=1;
        }
        else if(rt[i]>0)
        {
            time+=ts;
            rt[i]-=ts;
        }
        if(rt[i]==0 && flag==1)
        {
            remain--;
            tat[i]=time-at[i];
            wt[i]=tat[i]-bt[i];
            ct[i]=time;
            ttat+=tat[i];
            twt+=wt[i];
            flag=0;
        }
        if(i==n-1)
            i=0;
        else if(at[i+1]<time)
            i++;
        else
            i=0;

    }
    printf("Process\tArrival time\tBurst time\tCompletion time\tturnaround time\twaiting time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("%d %d",ttat,twt);
}
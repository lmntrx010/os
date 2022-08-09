#include<stdio.h>
struct proc
{
    int pid;
    int at;
    int bt;
    int ct,wt,tat,rt,start_time;
}ps[100];

int findmax(int a,int b)
{
    return (a>b)?a:b;
}


int main()
{
    int i,j,n;
    double avgwt,avgtat;
    printf("Enter the number of process");
    scanf("%d",&n);
    printf("Input arrival time and burst time");
    for(i=0;i<n;i++)
    {
        ps[i].pid=i+1;
        scanf("%d",&ps[i].at);
        scanf("%d",&ps[i].bt);
    }
    for(i=0;i<n;i++)
    { 
        ps[i].start_time=(i==0)?ps[i].at:findmax(ps[i-1].ct,ps[i].at);
        ps[i].ct=ps[i].start_time+ps[i].bt;
        ps[i].tat=ps[i].ct-ps[i].at;
        ps[i].wt=ps[i].tat-ps[i].bt;
        ps[i].rt=ps[i].wt;
        avgwt+=ps[i].wt;
        avgtat+=ps[i].tat;
    }
    avgwt=avgwt/n;
    avgtat=avgtat/n;
    printf("Process\tArrival time\tBurst time\tCompletion time\tturnaround time\twaiting time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt);
    }
    printf("%0.3f %0.3f",avgwt,avgtat);
}
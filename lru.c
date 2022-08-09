#include<stdio.h>
#include <stdbool.h>
int min(int f[],int a)
{
    int i,loc;
    int min=f[0];
    for(i=1;i<a;i++)
    {
        if(f[i]<min)
        {
            min=f[i];
            loc=i;
        }
    }
    return loc;

}
void printframe(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int n_f,n_p,counter,i,j,fault=0,loc;
    int flag1,flag2;
    printf("Enter the number of pages: ");
    scanf("%d",&n_p);
    printf("Enter the number of franes: ");
    scanf("%d",&n_f);
    int frame[n_f];
    int page[n_p];
    int time[n_f];
    printf("Enter the pages");
    for(i=0;i<n_p;i++)
    {
        scanf("%d",&page[i]);
    }
    for(i=0;i<n_f;i++)
    {
        frame[i]=-1;
    }
    for(i=0;i<n_p;i++)
    {
        flag1=0,flag2=0;
        for(j=0;j<n_f;j++)
        {
            if(page[i]==frame[j])
            {
                counter++;
                time[j]=counter;
                printframe(frame,n_f);
                flag1=1,flag2=1;
                break;
            }
        }
        if(flag1==0)
        {
            for(j=0;j<n_f;j++)
            {
                if(frame[j]==-1)
                {
                    counter++;
                    fault++;
                    time[j]=counter;
                    frame[j]=page[i];
                    printframe(frame,n_f);
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0)
        {
            for(j=0;j<n_f;j++)
            {
                loc=min(time,n_f);
                counter++;
                fault++;
                time[loc]=counter;
                frame[loc]=page[i];
                printframe(frame,n_f);
                break;
            }
        }
    }
    printf("Page fault:%d",fault);

}
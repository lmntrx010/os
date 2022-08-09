#include<stdio.h>
#include <stdbool.h>
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
    int n_f,n_p,count=0,i,j,fault=0,loc;
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
        for(j=0;j<n_f;j++)
        {
            if(frame[j]==page[i])
            {
                break;
            }
        }
        if(j==n_f)
        {
            frame[count++]=page[i];
            fault++;
        }
        printframe(frame,n_f);
        if(count==n_f)
            count=0;
    }
    printf("Page fault:%d",fault);
}
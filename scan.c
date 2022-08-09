#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,head,index,move,size;
    int rq[n];
    int tot=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the i/o:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("Enter the head");
    scanf("%d", &head);
    printf("Enter the move:");
    scanf("%d", &move);
    printf("Enter the size of disk");
    scanf("%d", &size);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
            {
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(head<rq[i])
        {
            index=i;
            break;
        }
    }
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            tot+=abs(rq[i]-head);
            head=rq[i];
            printf("%d ",tot);
        }
        tot+=abs(size-1-rq[i-1]);
        head=size-1;
        for(i=index-1;i>=0;i--)
        {
            tot+=abs(rq[i]-head);
            head=rq[i];
            printf("%d ",tot);
        }
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            tot+=abs(rq[i]-head);
            head=rq[i];
            printf("%d ",tot);
        }
        tot+=abs(0-rq[i+1]);
        head=0;
        printf("%d ",tot);
        for(i=index;i<n;i++)
        {
            tot+=abs(rq[i]-head);
            head=rq[i];
            printf("%d ",tot);
        }
    }
    printf("Total head movement:%d",tot);
}
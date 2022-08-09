#include<stdio.h>


int main()
{
    int n,i,j,k,m;
    int flag,ind=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the number of resources:");
    scanf("%d",&m);
    printf("Enter the allocated memory:\n");
    int alloc[n][m],max[n][m],available[m],need[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the maximum memory:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    printf("Enter available matrix:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&available[i]);
    }
    int work[n],safesequence[n],finish[n];
    for(i=0;i<m;i++)
    {
        work[i]=available[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            flag=0;
            for(j=0;j<m;j++)
            {
                if(need[i][j]>work[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=0;j<m;j++)
                {
                    work[j]+=alloc[i][j];
                }
                safesequence[ind++]=i;
                finish[i]=1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",safesequence[i]);
    }
}
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
struct pagetable
{
    int frame_no;
    int valid;
};
bool ispagepresent(struct pagetable PT[],int a)
{
    if(PT[a].valid==0)
        return false;
    else
        return true;
}
void updatepage(struct pagetable PT[],int page,int pgno,int state)
{
    PT[page].frame_no=pgno;
    PT[page].valid=state;
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
    int n,i,pagefault=0,current=0;
    bool flag=false;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    int no_of_frames;
    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);
    int frame[no_of_frames];
    for(i=0;i<no_of_frames;i++)
        frame[i]=0;
    printf("Enter the pages:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    struct pagetable PT[50];

    for(i=0;i<n;i++)
    {
        PT[i].valid = 0;
    }
    for(i=0;i<n;i++)
    {
        if(!(ispagepresent(PT,pages[i])))
        {
            pagefault++;
            if(flag==false && current<no_of_frames)
            {
                frame[current]=pages[i];
                printframe(frame,no_of_frames);
                updatepage(PT,pages[i],current,-1);
                current++;
                if(current==no_of_frames)
                {
                    current=0;
                    flag=true;
                }
            }
            else
            {
                updatepage(PT,frame[current],-1,0);
                frame[current]=pages[i];
                printframe(frame,no_of_frames);
                updatepage(PT,pages[i],current,-1);
                current=(current+1)%no_of_frames;
            }
        }
    }
    printf("Page fault=%d",pagefault);
    printf("Page hit:%d",n-pagefault);
}
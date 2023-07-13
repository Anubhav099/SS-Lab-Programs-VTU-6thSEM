#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ch, YN, i, f;
    char frame[10],str[25];

    printf("\nEnter the no of empty frames: ");
    scanf("%d",&f);

    printf("\nEnter the string: ");
    scanf("%s",str);
    int l = strlen(str);

    for(i=0;i<f;i++)    frame[i]=-1;

    do
    {
        printf("\n*********** MENU ***********");
        printf("\n1:FIFO\n2:LRU");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        for(i=0;i<f;i++) frame[i]=-1;
	    printf("\nPAGE\t\tFRAMES\t\tFAULTS");
        switch(ch)
        {
            case 1: FIFO(str,frame,l,f); break;

            case 2: LRU(str,frame,l,f);
        }
        printf("\n\nPress 0 to Exit and 1 to continue : ");
        scanf("%d",&YN);
    } while(YN==1);

    return(0);
}

void FIFO(char str[],char frame[],int l,int f)
{
    int i,j=0,k,flag=0,cnt=0;
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
        {
            if(frame[k]==str[i])
                flag=1;
        }

        if(flag==0)
        {
            printf("\n%c\t",str[i]);
            frame[j]=str[i];
            j++;
            for(k=0;k<f;k++) printf("\t%c",frame[k]);
            printf("\tPage-fault%d",cnt);
            cnt++;
        }

        else
        {
            flag=0;
            printf("\n%c\t",str[i]);
            for(k=0;k<f;k++) printf("\t%c",frame[k]);
            printf("\tNo page-fault");
        }
        if(j==f) j=0;
    }
}

void LRU(char str[],char frame[],int l,int f)
{
    int i,j=0,k,m,flag=0,cnt=0,top=0;
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
            if(frame[k]==str[i])
            {
                flag=1;
                break;
            }

        printf("\n%c\t",str[i]);
        if(j!=f && flag!=1)
        {
            frame[top]=str[i];
            j++;
            if(j!=f) top++;
        }
        else
        {
            if(flag!=1)
            {
                for(k=0;k<top;k++)  frame[k]=frame[k+1];
                frame[top]=str[i];
            }
            else if(flag==1)
            {
                for(m=k;m<top;m++)  frame[m]=frame[m+1];
                frame[top]=str[i];
            }
        }

        for(k=0;k<f;k++) printf("\t%c",frame[k]);

        if(flag==0)
        {
            printf("\tPage-fault%d",cnt);
            cnt++;
        }
        else printf("\tNo page fault");
        flag=0;
    }
}
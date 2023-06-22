#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stk[25],input[25];
char act[]="SHIFT->", ac[]="REDUCE TO E";
int i=0; // pointer for the stack array
int j=0; // pointer for the input array
int c=0; // will store the length of input
int z=0; // interation variable

void main()
{
	printf("GRAMMAR is:\n E->E+E \n E->E*E \n E->(E) \n E->id");
	printf("\nEnter input string: ");
	scanf("%s",input);
	c = strlen(input);
	printf("\nStack \t   Input \t Action\n");
	for(j=0; j<c; i++,j++)
		if(input[j]=='i' && input[j+1]=='d')
		{
			stk[i]=input[j];
			stk[i+1]=input[j+1];
			stk[i+2]='\0';
			input[j]=' ';
			input[j+1]=' ';
			printf("\n$%s\t%s$\t%s id",stk,input,act);
			check();
		}
		else
		{
			stk[i]=input[j];
			stk[i+1]='\0';
			input[j]=' ';
			printf("\n$%s\t%s$\t%s %c",stk,input,act,stk[i]);
			check();
		}
	printf("\n");
}

void check()
{
	for(z=0; z<c; z++)
		if(stk[z]=='i' && stk[z+1]=='d')
		{
			stk[z]='E';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,input,ac);
			j++;
		}
	for(z=0; z<c; z++)
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
			reduce();
	for(z=0; z<c; z++)
		if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
			reduce();
	for(z=0; z<c; z++)
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
			reduce();
}

void reduce()
{
	stk[z]='E';
	stk[z+1]='\0';
	stk[z+1]='\0';
	printf("\n$%s\t%s$\t%s",stk,input,ac);
	i=i-2;
}

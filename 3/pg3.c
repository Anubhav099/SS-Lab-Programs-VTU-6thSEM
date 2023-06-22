#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char prod[3][10]={"A->aBa","B->bB","B->@"}, input[25],stack[25];
int top=-1, i=0;

void push(char item)
{
	stack[++top]=item;
}

void pop()
{
	top=top-1;
}

void stackpush(char p)
{
	pop();
	if(p=='A')	
		for(int j=strlen(prod[0])-1;j>=3;j--)
			push(prod[0][j]);
	else	
		for(int j=strlen(prod[1])-1;j>=3;j--)
			push(prod[1][j]);
}

void main()
{
	printf("first(A)={a}\tfollow(A)={$}\n");
	printf("first(B)={b,@}\tfollow(B)={a}\n\n");
	printf("\t a \t b \t $ \n");
	printf("A\t%s\n",prod[0]);
	printf("B\t%s\t%s\n\n",prod[2],prod[1]);
	printf("Enter the input string terminated with '$' to parse: ");
	scanf("%s",input);
	for(i=0;input[i]!='\0';i++)
		if((input[i]!='a')&&(input[i]!='b')&&(input[i]!='$'))
		{
			printf("Invalid String.\n");
			exit(0);
		}
	if(input[i-1]!='$')
	{
		printf("\n\nInput string entered without end marker $\n");
		exit(0);
	}
	push('$');
	push('A');
	i=0;
	printf("\nstack\tInput\taction");
	printf("\n------------------------\n");
	while(i!=strlen(input) && stack[top]!='$')
	{
		printf("\n");
		for(int l=0;l<=top;l++)
			printf("%c",stack[l]);
		printf("\t");
		for(int l=i;l<strlen(input);l++)
			printf("%c",input[l]);
		printf("\t");
		if(stack[top]=='A')
		{
			printf("A->aBa");
			stackpush('A');
		}
		else if(stack[top]=='B')
			if(input[i]=='b')
			{
				printf("B->bB");
				stackpush('B');
			}			

			else
			{
				printf("B->@");
				printf("\tmatched @");
				pop();
			}
		else if(stack[top]==input[i])
		{
			printf("pop %c",input[i]);
			printf("\tmatched %c",input[i]);
			pop();
			i++;
		}
		else 	break;
	}
	if(stack[top]=='$' && input[i]=='$')
	{
		printf("\n$\t$");
		printf("\nValid string Accepted\n");
	}
	else
		printf("\nInvalid string rejected\n");
}

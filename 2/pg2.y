%{
#include <stdio.h>
%}

%token A B

%%
S:A S|B;
%%

int main()
{
	printf("Enter expression: ");
	yyparse();
	printf("Expression is valid!!!\n");
}
int yyerror()
{
	printf("Expression is Invalid.\n");
	exit(0);
}

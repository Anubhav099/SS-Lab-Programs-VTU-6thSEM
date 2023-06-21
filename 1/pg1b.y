%{
#include<stdio.h>
%}
	
%token NUM
%left '+''-'
%left '*''/'

%%
Start:E {printf("Valid expression\n");printf("Result=%d\n",$$);}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {if($3==0) {printf("Divide by zero error\n"); exit(0);} else {$$=$1/$3;}}
|'('E')' {$$=$2;}
|NUM {$$=$1;};
%%

void main()
{
	printf("Enter Expression:");
	yyparse();
}

int yyerror()
{
	printf("Invalid expression\n");
	exit(0);
}

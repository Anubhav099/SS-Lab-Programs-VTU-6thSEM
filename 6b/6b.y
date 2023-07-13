%{
#include<stdio.h>
extern *yyin;
int id=0, dig=0, key=0, op=0;
%}
%token DIGIT ID KEY OP

%%
S: DIGIT S { dig++; }
| ID S { id++; }
| KEY S { key++; }
| OP S {op++;}
| DIGIT { dig++; }
| ID { id++; }
| KEY { key++; }
| OP { op++;};
%%

void main() 
{
	yyin = fopen("input.c", "r"); 
	while(!feof(yyin))
	{
		yyparse();
	}
	fclose(yyin);
	printf("Numbers= %d\nIdentifiers= %d\nOperators= %d\nKeywords= %d\n",dig, id, op, key);
}

void yyerror() {
	printf("Error!");
	exit(-1);
}

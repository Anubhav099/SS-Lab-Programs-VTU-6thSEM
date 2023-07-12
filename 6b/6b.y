%{
#include<stdio.h>
extern FILE *yyin;
int id=0, dig=0, key=0, op=0;
%}
%token DIGIT ID KEY OP

%%
input:
DIGIT input { dig++; }
| ID input { id++; }
| KEY input { key++; }
| OP input {op++;}
| DIGIT { dig++; }
| ID { id++; }
| KEY { key++; }
| OP { op++;}
;
%%

void main() 
{
	FILE *myfile = fopen("input.c", "r"); 
	if (!myfile) 
	{
		printf("Can't open input.c!");
		return -1;
	}
	yyin = myfile;
	do{
		yyparse();
	}while (!feof(yyin));

	printf("Numbers= %d\nIdentifiers= %d\nOperators= %d\nKeywords= %d\n",dig, id, op, key);
}

void yyerror() {
	printf("EEK, parse error! Message: ");
	exit(-1);
}

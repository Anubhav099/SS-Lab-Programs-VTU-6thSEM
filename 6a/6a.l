%{
#include<stdio.h>
int sl=0;
int ml=0;
%}

%%
"/*"[a-zA-Z0-9' '\t\n]+"*/" ml++;
"//".* sl++;
%%

void main()
{
	yyin=fopen("f1.c","r");
	yyout=fopen("f2.c","w");
	yylex();
	fclose(yyin);
	fclose(yyout);
	printf("\nCount of single line comments = %d\n",sl);
	printf("\nCount of multiline comments = %d\n",ml);
}

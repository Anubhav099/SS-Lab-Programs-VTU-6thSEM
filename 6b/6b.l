%{
#include <stdio.h>
#include "y.tab.h"
extern yylval;
%}

%%
[ \t] ;
[\+\-\*\/\=\<\>] {printf("Operator detected= %s\n",yytext); return OP;}
[0-9]+ {yylval=atoi(yytext); printf("Number detected= %d\n",yylval); return DIGIT;} 
int|char|bool|float|void|for|do|while|if|else|return {printf("Keyword detected= %s\n",yytext); return KEY;}
[a-zA-Z0-9]+ {printf("Identifier detected= %s\n",yytext); return ID;}
. ;
%%

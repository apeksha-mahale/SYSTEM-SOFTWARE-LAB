%{//2. Develop a lex program to count the number of C lines in a given C program
%}

%{#include<stdio.h>
int count = 0;
%}

%x C
%%
"/*"[.]*"*/"	{count++;}
"/*"		{BEGIN C;}
<C>"*/"		{BEGIN 0; count++;}
<C>\n		{;}
<C>.		{;}
\/\/.*		{count++;}
%%

int main()
{
	yyin=fopen("data.c","r");
	yylex();
	printf("Count: %d\n", count);
	return 0;
}

int yywrap()
{
	return 1;
}

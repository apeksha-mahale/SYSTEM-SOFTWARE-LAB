%{//4.Develop a lex program to recognize and count the number of
//identifiers in a given input file.
%}

%{
#include <stdio.h>
int count = 0;
%}

id	[a-zA-Z_][a-zA-Z0-9_]*

%%
{id}	{count++; printf("%s\n", yytext);}
.*	{;}
\n	{;}
%%

int main()
{
	yyin = fopen("id.txt", "r");
	printf("Valid identifiers are: \n");
	yylex();
	printf("\nCount: %d\n", count);
	return 0;
}

int yywrap()
{
	return 1;
}

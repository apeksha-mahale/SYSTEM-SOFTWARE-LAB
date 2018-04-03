%{//1. Develop a lex program to count the number of characters, 
//words, spaces and lines in a given input file
%}

%{#include<stdio.h>
int chars = 0;
int word = 0;
int space = 0;
int line = 0;
%}

%%
[^ \n\t]+		{word++, chars+=yyleng;}
\n			{line++;}
\t			{space++;}
" "			{space++;}
%%

int main()
{
	yyin=fopen("data.txt","r");
	yylex();
	printf("Count: \nChar: %d\nWord: %d\nSpace: %d\nLine: %d\n", chars, word, space, line);
	return 0;
}

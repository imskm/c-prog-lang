#include<stdio.h>

/**
 * 1.16 Revise the main routine of the longest-line program so it will
 * correctly print the lenght of arbitrarily long input lines, and as
 * much as possible of the text.
 */

#define MAXLINE 1000

int xgetline(char line[], unsigned int lim);
void copy(char des[], char src[]);

int main()
{
	char curline[MAXLINE];
	int len;

	while((len = xgetline(curline, MAXLINE)) > 0)
	{
		printf("%2d: %s", len, curline);
	}

	return 0;
}

/**
 * getline: read a line ('\n' is included) at the end of the line
 *
 * @param char []  stores read line
 * @param unsigned int lim  max char read limit
 *
 * @return int  number of chars read
 */
int xgetline(char line[], unsigned int lim)
{
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		line[i] = c;

	if(c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}

/**
 * copy: copy chars from src to dest
 *
 * @param char des[]  destination, where src will be copied
 * @param char src[]  source string to be copied
 *
 * @return void
 */
void copy(char des[], char src[])
{
	for(int i = 0; des[i] = src[i]; ++i) ;
}

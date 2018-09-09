#include<stdio.h>

/**
 * 1.18 Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines.
 */

#define MAXLINE 1000

int xgetline(char line[], unsigned int lim);
void copy(char des[], char src[]);
unsigned int rtrim(char s[]);

int main()
{
	char curline[MAXLINE];
	int len;

	while((len = xgetline(curline, MAXLINE)) > 0)
	{
		// if line is not entirely empty
		if(len > 1)
		{
			rtrim(curline);
			printf("%2d: %s", len, curline);
		}
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

/**
 * rtrim: removes white space characters from end of the string
 * white space includes ' ', '\t', '\n'
 *
 * @param char s[]  string s to be trimed
 *
 * @return int  number of whitespace chars trimed
 */
unsigned int rtrim(char s[])
{
	int i, trimed;

	i = trimed = 0;
	// Counting the length of the string s
	while(s[i++]);
	--i;

	// Handeling newline character at the end of the string
	if(s[--i] == '\n') --i;

	// removing whitespace
	while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
	{
		--i;
		++trimed;
	}
	s[++i] = '\n';
	s[++i] = '\0';

	return trimed;
}

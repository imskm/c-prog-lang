#include<stdio.h>

/**
 * 1.19 Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#define MAXLINE 1000

int xgetline(char line[], unsigned int lim);
void reverse(char s[]);

int main()
{
	char curline[MAXLINE];
	int len;

	while((len = xgetline(curline, MAXLINE)) > 0)
	{
		// if line is not entirely empty
		if(len > 1)
		{
			reverse(curline);
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
 * reverse: reverses string
 *
 * @param char s[]  string s to be reversed
 *
 * @return void
 */
void reverse(char s[])
{
	int i, j;
	char t;

	i = j = 0;
	// Counting the length of the string s
	while(s[i++]);
	--i;	// index of '\0'

	// taking care of newline char left by getline function
	// and leaving '\n' at the end of string
	if(s[i - 1] == '\n') j = i - 2;
	else j = i - 1;
	i = 0;

	// Reversing string
	while(i < j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		++i; --j;
	}
}


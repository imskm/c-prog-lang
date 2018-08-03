#include<stdio.h>

/**
 * Exercise 1.9: Write a program to copy its input to its output,
 * replace each string of one or more blanks by a single blank.
 */

#define OUT 0
#define IN 1

int main()
{
	int c, state;

	state = OUT;

	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			if(state == OUT)
			{
				printf("%c", c);
				state = IN;
			}
		}
		else
		{
			printf("%c", c);
			state = OUT;
		}
	}

	return 0;
}

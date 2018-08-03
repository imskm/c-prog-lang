#include<stdio.h>

/**
 * Write a program that prints its input one word per line.
 */

#define OUT 0
#define IN 1

int main()
{
	int c, state = OUT;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			if(state == OUT)
			{
				puts("");
				state = IN;
			}
		}
		else
		{
			putchar(c);
			state = OUT;
		}
	}
	return 0;
}

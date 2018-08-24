#include<stdio.h>

/**
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw histogram with the bars horizontal; a vertical
 * orientation is more challening.
 */

#define OUT 0
#define IN 1
#define RANGE 5
#define ARR_SIZE 10
#define FACTORIZEBY 1

int main()
{
	/**
	 * lenword[0] = 0 - 5
	 * lenword[1] = 5 - 10
	 * lenword[2] = 10 - 15
	 * lenword[3] = 15 - 20
	 * inclusive - exclusive
	 */
	int c, lenwords[ARR_SIZE] = {0}, len, state, hash_tag;
	
	len = 0;
	state = OUT;
	// Counting length of each word and storing in lenword array
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
		{
			state = OUT;
		}
		else if(state == OUT)
		{
			state = IN;
		}

		if(state == IN)
			len++;
		else if(state == OUT && len != 0)
		{
			lenwords[ len / RANGE]++;
			len = 0;
		}
	}

	// printing the Histogram
	for(int i = 0; i < ARR_SIZE; ++i)
	{
		printf("%2d - %2d : %6d | ", i * RANGE, (i + 1) * RANGE, lenwords[i]);
		hash_tag = lenwords[i] / FACTORIZEBY;
		for(int j = 0; j < hash_tag; ++j)
			printf("#");

		printf("\n");
	}

	return 0;
}

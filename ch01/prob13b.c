#include<stdio.h>

/**
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw histogram with the bars horizontal; a vertical
 * orientation is more challening.
 *
 * execute: ./a.out < textfile
 */

#define MAX(a, b) (((a) > (b))? (a) : (b))

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
	int c, lenwords[ARR_SIZE] = {0}, len, state, hash_tag, max;

	puts("    Vertical Histogram of Length of words");
	puts("");
	
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

	/**
	 * My algorithm for printing histogram in vertical
	 *
	 * 1: Find max of lenwords
	 * 2: while max > 0
	 *      for i <-- 0 to size of lenwords
	 *        if max <= lenwords[i]
	 *          print "#"
	 *        else
	 *          print " "
	 *      print newline
	 *      max <-- max - 1
	 * 3: end
	 *
	 */

	// printing the Histogram in Vertical order
	max = lenwords[0];
	for(int i = 1; i < ARR_SIZE; ++i)
		max = MAX(max, lenwords[i]);

	// printing h
	while(max)
	{
		for(int i = 0; i < ARR_SIZE; ++i)
		{
			if(max <= lenwords[i])
				printf("  #   ");
			else
				printf("      ");
		}
		printf("\n");
		max--;
	}

	// printing histogram labels at the bottom of vertical bars
	for(int i = 0; i < ARR_SIZE; ++i)
		printf("%2d-%-2d ", i * RANGE, (i + 1) * RANGE);

	puts("");

	return 0;
}

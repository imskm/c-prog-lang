#include<stdio.h>

/**
 * 1.14: Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */

#define SIZE 100
#define LOWER_BOUND 33
#define UPPER_BOUND 126
#define ARR_SIZE 10
#define RANGE 100

int main()
{
	/**
	 * Histogram
	 * hist[0] = 0 - 5
	 * hist[1] = 5 - 10
	 * hist[2] = 10 - 15
	 * hist[3] = 15 - 20
	 * inclusive - exclusive
	 */
	int c, chars[SIZE] = {0}, hist[ARR_SIZE] = {0}, hash_tag;

	// Finding frequencies
	// index 0 represents ascii value 33 (LOWER_BOUND)
	while((c = getchar()) != EOF)
	{
		if(c >= LOWER_BOUND && c <= UPPER_BOUND)
			chars[ c - LOWER_BOUND ]++;
	}

	// Finding histogram for different frequencies of character
	for(int i = 0; i < SIZE; ++i)
		if(chars[i]) hist[ chars[i] / RANGE ]++;

	// printing the Histogram
	for(int i = 0; i < ARR_SIZE; ++i)
	{
		printf("%3d - %3d : %6d | ", i * RANGE, (i + 1) * RANGE, hist[i]);
		hash_tag = hist[i];
		for(int j = 0; j < hash_tag; ++j)
			printf("#");

		printf("\n");
	}


	return 0;
}

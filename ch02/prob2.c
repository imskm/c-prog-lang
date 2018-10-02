#include<stdio.h>

/**
 * 2.2: Write a loop equivalent to the for loop above without using
 * && or ||.
 */

int main()
{
	int i, lim = 1000;
	char c, s[1000] = {0};

	for(i = 0; i < lim - 1; ++i)
	{
		if((c = getchar()) == '\n')
			break;
		if(c == EOF)
			break;
		s[i] = c;
	}
	s[i] = '\0';

	return 0;
}

#include<stdio.h>

/**
 * Modify the temperature coversion program to print the table
 * in reverse order, taht is, from 300 degree to 0.
 */

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius Fahrenheit\n");
	for(fahr = upper; fahr >= lower; fahr -= step)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%7.1f %10.0f\n", celsius, fahr);
	}

	return 0;
}

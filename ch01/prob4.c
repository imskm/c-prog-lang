#include<stdio.h>

/**
 * Print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300;
 */
int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius Fahrenheit\n");
	for(fahr = lower; fahr <= upper; fahr += step)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%7.1f %10.0f\n", celsius, fahr);
	}

	return 0;
}

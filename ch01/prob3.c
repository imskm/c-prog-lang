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

	printf("Fahrenheit Celsius\n");
	for(fahr = lower; fahr <= upper; fahr += step)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%10.0f %7.1f\n", fahr, celsius);
	}

	return 0;
}

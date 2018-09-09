#include<stdio.h>

/**
 * 1.15 Rewrite the temperature conversion program of Section 1.2 to
 * use a function of conversion.
 */

void fahren_to_celcius()
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
}

int main()
{
	// Calling fahren_to_celcius() function
	// to print temperature table
	fahren_to_celcius();

	return 0;
}

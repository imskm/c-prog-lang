#include<stdio.h>
#include<limits.h>

/**
 * 2.1: Write a program to determine the ranges of char, short, int, and long variables, both
 * signed and unsigned, by printing appropriate values from standard headers and by direct
 * computation. Harder if you compute them: determine the ranges of the various floating-
 * point types.
 */

int main()
{
	// Unsigned Char range
	printf("Unsigned Char ragne        %22d - %22d\n", 0, UCHAR_MAX);
	
	// Signed Char range
	printf("Signed Char ragne          %22d - %22d\n", SCHAR_MIN, SCHAR_MAX);

	// Unsigned short range
	printf("Unsigned short range       %22d - %22d\n", 0, USHRT_MAX);

	// Signed short range
	printf("Signed short range         %22d - %22d\n", SHRT_MIN, SHRT_MAX);

	// Unsigned int range
	printf("Unsigned int range         %22d - %22u\n", 0, UINT_MAX);

	// Signed int range
	printf("Signed int range           %22d - %22d\n", INT_MIN, INT_MAX);

	// Unsigned long range
	printf("Unsigned long range        %22d - %22lu\n", 0, ULONG_MAX);

	// Signed long range
	printf("Signed long range          %22ld - %22ld\n", LONG_MIN, LONG_MAX);
	return 0;
}

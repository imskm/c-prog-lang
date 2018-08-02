/**
 * Escape character test
 * Tested on cc 5.4 compiler
 */
#include<stdio.h>

int main()
{
	int a;
	printf("hello, ");
	//printf("world\c"); // \c doesn't work in cc 5.4
	printf("\n");

	// alert (Bell) Character
	printf("\a");		// Didn't work

	// Backspace escapse character
	printf("Backspace\b"); 	// After n \b add n spaces to erase the character from screen
	scanf("%d", &a);
	
	// Formfeed
	printf("Form Feed\fAfter form feed\fAgain after form feed\n");
	/**
	 * OUTPUT
	 * Form Feed
	 *          After form feed
	 *                         Again after form feed
	 */

	// Carriage Return
	printf("Carriage Return\rAfter Carriage return\n");

	// Horizontal tab
	printf("Horizontal tab\tTabbed\n");

	// Vertical tab
	printf("Vertical Tab\vTabbed\vTabbed Again\n");

	puts("");
	return 0;
}

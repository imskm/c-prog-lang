#include<stdio.h>

// in book main function is written as main()
// with no return type. I have done differently below
// to avoid compiler warning. But it doesn't matter
// if no return type is mentioned then c defaults to in
int main()
{
	printf("hello, ");
	printf("world");
	printf("\n");

	return 0;
}

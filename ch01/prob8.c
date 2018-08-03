#include<stdio.h>

int main()
{
	int nblanks, ntabs, nlines, c;

	nblanks = ntabs = nlines = 0;
	while((c = getchar()) != EOF)
	{
		if(c == ' ') ++nblanks;
		if(c == '\t') ++ntabs;
		if(c == '\n') ++nlines;
	}

	printf("Blanks: %d\n", nblanks);
	printf("Tabs: %d\n", ntabs);
	printf("Lines: %d\n", nlines);

	return 0;
}

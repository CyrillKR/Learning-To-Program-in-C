#include <stdio.h>

main()
{
	int c;
	int nl, nt, nb;

	nl = 0;
	nt = 0;
	nb = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			++nl;
		}
		else if (c == '\t')
		{
			++nt;
		}
		else if (c == ' ')
		{
			++nb;
		}
	}

	printf("New lines: %d\n", nl);
	printf("New tabs: %d\n", nt);
	printf("New blanks: %d\n", nb);
}

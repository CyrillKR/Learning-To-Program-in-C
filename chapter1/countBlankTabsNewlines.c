#include <stdio.h>

int main()
{
	int c;	
	int nl,nt,nb;

	nl = 0;
	nt = 0;
	nb = 0;

	while((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
			printf("New lines: %d\n",nl);
		} else if (c == '\t') {
			++nt;
			printf("New tabs: %d\n", nt);
		} else if (c == ' ') {
			++nb;
			printf("New blanks: %d\n",nb);
		} else {
			printf("I'm only counting new lines,tabs and blanks");
			printf("So far, there are %d lines, %d tabs and %d blanks",nl,nt,nb);
		}
	}

	return 0;
}

#include <stdio.h>

int main()
{
	int c;

	printf("%d\n", getchar() != EOF); // Exercise 1-6, the value is 1.	
	printf("The value of EOF is: %d\n",EOF); // Exercise 1-7, the value is -1.

	while((c=getchar()) != EOF)
		putchar(c);

	return 0;
}

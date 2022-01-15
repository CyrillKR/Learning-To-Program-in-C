#include <stdio.h>

int main()
{	
	printf("The number of eggs for the day: \n");
	int eggs;
	scanf("%i", &eggs);
	
	double dozen = (double) eggs / 12;

	printf("You have %f dozens of eggs\n",dozen);

	return 0;
}

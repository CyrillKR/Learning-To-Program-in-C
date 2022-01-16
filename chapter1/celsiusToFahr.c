#include <stdio.h>

int main()
{	
	float celsius, fahr;
	int lower, upper, step;
	
	lower = -20;
	upper = 100;
	step = 5;

	celsius = lower;
	
	printf("Celsius\tFahrenheit\n");
	while(celsius <= upper) {
		fahr = (celsius * (9.0/5.0)) + 32.0;
		printf("%3.0f %6.0f\n",celsius, fahr);
		celsius += step;
	}

	return 0;
}

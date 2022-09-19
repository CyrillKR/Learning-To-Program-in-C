#include <stdio.h>

/*
    Exercise 1 - 15
    Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

float celcius_to_fahrenheit(float c);
float fahrenheit_to_celcius(float f);

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = celsius = lower;

    printf("F\tC\n");

    while (fahr <= upper)
    {
        printf("%3.0f\t%3.1f\n", fahr, fahrenheit_to_celcius(fahr));
        fahr += step;
    }

    printf("\nC\tF\n");

    while (celsius <= upper)
    {
        printf("%3.0f\t%3.0f\n", celsius, celcius_to_fahrenheit(celsius));
        celsius += step;
    }

    return 0;
}

float celcius_to_fahrenheit(float c)
{
    return (c * (9.0 / 5.0)) + 32.0;
}

float fahrenheit_to_celcius(float f)
{
    return (5.0 / 9.0) * (f - 32.0);
}
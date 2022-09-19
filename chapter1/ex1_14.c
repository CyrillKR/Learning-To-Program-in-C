#include <stdio.h>

#define CHARSET_MAX 127 /* ASCII */

/*
    Exercise 1 -14

    Write a program to print a histogram of the frequencies
    of different characters in its input.
*/

main()
{
    int c, i, j, hv;
    int nchars[CHARSET_MAX];
    int cchars[CHARSET_MAX];

    for (i = 0; i < CHARSET_MAX + 1; ++i)
        nchars[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (!(c == ' ' || c == '\n' || c == '\t'))
            ++nchars[c];
    }

    /* Vertical Histogram */
    for (i = 0; i < CHARSET_MAX + 1; ++i)
    {
        if (nchars[i] > 0)
        {
            printf("%c ", i);
            for (j = 0; j < nchars[i]; ++j)
                printf("|");
            printf("\n");
        }
    }
    printf("\n");

    /* Vertical Histogram, same concept as the histogram in EX 1-13 */
    hv = 0;
    for (i = 0; i < CHARSET_MAX + 1; ++i)
    {
        if (nchars[i] > hv)
            hv = nchars[i];
    }

    /* Copying values for reference */
    for (i = 0; i < CHARSET_MAX + 1; ++i)
        cchars[i] = nchars[i];

    /* Printing the histogram */
    for (; hv > 0; --hv)
    {
        for (i = 0; i < CHARSET_MAX + 1; ++i)
        {
            if (cchars[i] > 0)
            {
                if (cchars[i] == hv)
                {
                    printf("*");
                    --cchars[i];
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    for (i = 0; i < CHARSET_MAX + 1; ++i)
    {
        if (nchars[i] > 0)
        {
            printf("%c", i);
        }
    }
    printf("\n");

    return 0;
}

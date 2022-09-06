#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_COUNT 30

/*
    Exercise 1 - 14:

    Write a program to print a histogram of the lengths of words
    in its input. It is easy to draw the histogram
    with the bars horizontal; a vertical orientation
    is more challenging.
*/

main()
{
    int pc, c, i, j, nw, ccount, state;
    int words[MAX_WORD_COUNT];

    nw = ccount = 0;
    state = OUT;

    /* Main input loop */
    while ((c = getchar()) != EOF)
    {
        if (!(c == ' ' || c == '\n' || c == '\t'))
            state = IN;
        else
            state = OUT;

        if (state == IN)
            ++ccount;
        else if (ccount == 0)
            ;
        else if (pc != ' ' && pc != '\n' && pc != '\t')
        {
            if (nw == MAX_WORD_COUNT)
            {
                words[nw] = ccount;
                printf("Max word count reached\n");
                break;
            }
            words[nw] = ccount;
            ++nw;
            ccount = 0;
        }

        pc = c;
    }

    printf("\nTotal of %d words!\n\n", nw);

    /* Horizontal Histogram */
    printf("Histrogram of their lengths horizontal:\n");
    for (i = 0; i < nw; ++i)
    {
        printf("%2d ", words[i]);
        for (j = 0; j < words[i]; ++j)
            printf("|");
        printf("\n");
    }
    printf("\n");

    /* Vertical Histrogram */
    int hv;
    int cwords[nw];
    hv = 0;

    /* Finding highest value */
    for (i = 0; i < nw; ++i)
    {
        if (words[i] > hv)
            hv = words[i];
    }

    /* Copying values for keep reference */
    for (i = 0; i < nw; ++i)
        cwords[i] = words[i];

    /* Printing the histogram */
    printf("Histrogram of their lengths vertical:\n");
    for (hv; hv > 0; --hv)
    {
        for (i = 0; i < nw; ++i)
        {
            if (cwords[i] == hv)
            {
                printf(" * ");
                --cwords[i];
            }
            else
            {
                printf("   ");
            }
        }
        printf(" \n");
    }
    for (i = 0; i < nw; i++)
    {
        printf(" %d ", words[i]);
    }
    printf("\n");
}
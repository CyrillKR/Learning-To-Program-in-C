#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c, nl, nw, state;

    nl = nw = 0;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            putchar('\n');
            state == OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
}
#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

/* This program doesn't account for the meaning of characters
   so "words" that consist of "!!!!!!!" or "@!$!@42173"
   or simply numbers are still considered to be words.

   An edge case for this programs is also reaching overflow if too
   many characters were written as `int` has a max of 32767
   (according to the machines of the time).                     */
#include <stdio.h>

/*
    Exercise 1 - 18:
    Write a program to remove trailing blanks
    and tabs from each line of input, and to delete
    entirely blank lines.
*/

#define MAXLINE 1000

int get_line(char line[]);
void print_line(char line[]);

int main()
{
    int c, lc, len, i, j;
    char current_line[MAXLINE];

    while ((c = get_line(current_line)) != EOF)
    {
        if (!(lc == '\n' && c == -2))
        {
            print_line(current_line);
        }
    }

    return 0;
}

int get_line(char line[])
{
    int c, pc, i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (i == MAXLINE - 1)
            break;

        if (!(c == ' ' && pc == ' ') && !(pc == '\t' && c == '\t'))
        {
            line[i] = c;
            ++i;
        }
        pc = c;
    }
    line[i] = '\0';

    return c;
}

void print_line(char line[])
{
    if (line[0] != '\0')
        printf("%s\n", line);
}
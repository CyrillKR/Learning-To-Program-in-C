#include <stdio.h>

/*
    Exercise 1 - 16:
    Revise the main routine of the longest-line
    program so it will correcty print the length
    of arbitrarily long input lines, and as much
    as possible of the text.

    Exercise 1 - 17:
    Write a program to print all inputs that are longer than 80 characters.
*/

#define MAXLINE 1000
#define LINE_LIMIT 10
#define LONG_LINE 80

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void print_text(char str[]);

int main()
{
    int len, max, lcount;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = lcount = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (lcount == LINE_LIMIT - 1)
            break;

        if (len > LONG_LINE)
        {
            printf("Line %d legnth: %d\n", lcount + 1, len);
            print_text(line);
        }

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
        ++lcount;
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void print_text(char line[])
{
    printf("%s", line);
}

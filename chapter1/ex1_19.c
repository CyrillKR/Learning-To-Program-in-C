#include <stdio.h>

/*
    Exercise 1 - 19:
    Write a funcion reverse(s) that reverses the character string s.
    Use it to write a program that reverses its input a line at a time.
*/

#define MAXLINE 1000

void reverse(char s[], char r[]);
int get_input(char line[]);
int count_chars(char s[]);

int main()
{
    int c;
    char current_line[MAXLINE];
    char reverse_line[MAXLINE];

    while ((c = get_input(current_line)) != EOF)
    {
        reverse(current_line, reverse_line);
        if (reverse_line[0] != '\0')
            printf("%s\n", reverse_line);
    }
}

void reverse(char s[], char r[])
{
    int i, len;

    len = count_chars(s);

    i = 0;
    for (--len; len >= 0; --len)
    {
        if (i == MAXLINE - 1)
            break;
        r[i] = s[len];
        ++i;
    }
    r[i] = '\0';
}

int get_input(char line[])
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i == MAXLINE - 1)
            break;
        line[i] = c;
    }
    line[i] = '\0';

    return c;
}

int count_chars(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}
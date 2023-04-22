#include <stdio.h>

/*
    Exercise 1 - 22:
    Write a program to "fold" long input lines into two or more
    shorter lines after the last non-blank character that occurs
    before the n-th column of input. Make sure your program does
    something intelligent with very long lines, and if there are
    no blanks or tabs before the specified column.
*/

#define TRUE 1
#define FALSE 0
#define MAX_COLUMN 10
#define MAX_CHARS 100
#define TAB_TO_SPACE 4

int is_tab(char single_char);
int is_new_line(char single_char);
int is_blank_char(char single_char);

int get_input(char line[]);
int detab(char text[], int index, int current_column);

void print_text(char line[]);
void clear_input(char line[]);

int main()
{
    int c;
    char text[MAX_CHARS];

    while ((c = get_input(text)) != EOF)
        ;
    print_text(text);
    clear_input(text);
    return 0;
}

int is_tab(char single_char)
{
    if (single_char == '\t')
    {
        return TRUE;
    }

    return FALSE;
}

int is_new_line(char single_char)
{
    if (single_char == '\n')
    {
        return TRUE;
    }

    return FALSE;
}

int is_blank_char(char single_char)
{
    if (is_new_line(single_char) || is_tab(single_char) || single_char == ' ')
    {
        return TRUE;
    }

    return FALSE;
}

int get_input(char line[])
{
    int c, cc, i, pc; /* c - char, cc - current column ,
                         i - index, pc - previous char */

    pc, cc = 0;

    for (i = 0; (c = getchar()) != EOF; ++i)
    {
        line[i] = c;

        if (is_new_line(c))
            cc = 0;

        if (cc == (MAX_COLUMN - 1))
        {
            if ((!is_blank_char(c)) && (!is_blank_char(pc)))
            {
                line[i] = '-';
            }

            if (is_tab(pc))
            {
                line[i - 1] = ' ';
            }

            i++;
            line[i] = '\n';
            i++;
            line[i] = c;

            cc = 0;
        }
        else
        {
            cc++;
        }

        pc = c;
    }

    if (is_new_line(pc))
    {
        line[i - 1] = '\0';
    }
    else
    {
        line[i] = '\0';
    }
    return c;
}

int detab(char text[], int index, int current_column)
{
    int j;
    for (j = 0; j < TAB_TO_SPACE; ++j)
    {
        if (current_column > MAX_COLUMN - 1)
            break;

        text[index] = ' ';
        ++index;
    }

    return index;
}

void print_text(char line[])
{
    printf("%s\n", line);
}

void clear_input(char line[])
{
    int index = 0;
    while (line[index])
    {
        line[index] = '\0';
        ++index;
    }
}

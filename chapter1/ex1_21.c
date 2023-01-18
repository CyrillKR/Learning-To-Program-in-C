#include <stdio.h>

/*
    Exercise 1 - 21:
    Write a program `entab` that replaces strings of blanks by the
    minimum number of tabs and blankes to acheive the same spacing.
    Use the same tab stops as for detab. When either a tab or
    a single blank would suffice to reach a tab stop, which should
    be given preference?

    I've given preference for tabs rather than blanks because
    this is way the array strings will be shorter.
*/

#define TAB_STOP 4   /* How many spaces for a tab */
#define MAXLINE 1000 /* Max line length */
#define IN 1         /* Defintions of whenever the iteration */
#define OUT 0        /* is inside a word or not */

int get_input(char line[]);
void print_text(char line[]);
void clear_input(char line[]);
int entab(char line[], int index);

int main(void)
{
    int c;
    char current_line[MAXLINE];

    while ((c = get_input(current_line)) != EOF)
        ;
    print_text(current_line);
    clear_input(current_line);
    return 0;
}

int get_input(char line[])
{
    int c, i;
    int blank_count = 0;
    int is_in_word = IN;

    for (i = 0; (c = getchar()) != EOF; ++i)
    {
        if (i == MAXLINE - 1)
            break;

        if (c == '\n' || c == '\t')
        {
            blank_count = 0;
            is_in_word = OUT;
            line[i] = c;
        }
        else if (c == ' ')
        {
            if (is_in_word)
                is_in_word = OUT;

            blank_count += 1;

            if (blank_count == TAB_STOP)
            {
                i = entab(line, i);
                blank_count = 0;
            }
            else
            {
                line[i] = c;
            }
        }
        else
        {
            blank_count = 0;
            is_in_word = IN;
            line[i] = c;
        }
    }

    line[i] = '\0';
    return c;
}

int entab(char line[], int index)
{
    int blank_count = 0;
    while (blank_count < TAB_STOP - 1)
    {
        if (line[index + 1])
        {
            line[index] = line[index + 1];
        }
        index--;
        blank_count++;
    }

    line[index] = '\t';
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

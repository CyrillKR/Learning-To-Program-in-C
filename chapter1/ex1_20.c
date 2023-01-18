#include <stdio.h>

/*
	Exercise 1-20:
	Write a program `detab` that replaces tabs in the input with the proper number of
	blanks to space to the next tab stop. Assume a fixed set of tabs stop, say every
	n columns. Should n be a variable or a symbolic parameter?

	I've chosen n to be a symbloc parameter as it's a constant value
	that doesn't change during the program's execution.
*/

#define TAB_TO_SPACE 4 /* How many spaces for a tab */
#define MAXLINE 1000   /* Max line length */

int get_input(char line[]);
void detab(char s[], int index);
void clear_input(char s[]);
void print_text(char s[]);

int main()
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
	for (i = 0; (c = getchar()) != EOF; ++i)
	{
		if (i == MAXLINE - 1)
			break;

		if (c == '\t')
		{
			detab(line, i);
			i += TAB_TO_SPACE - 1; /* Slight offset to avoid allocating garbage */
		}
		else
		{
			line[i] = c;
		}
	}

	line[i] = '\0';
	return c;
}

void detab(char s[], int index)
{
	int j;
	for (j = 0; j < TAB_TO_SPACE; ++j)
	{
		s[index] = ' ';
		++index;
	}
}

void clear_input(char s[])
{
	int start = 0;
	while (s[start])
	{
		s[start] = '\0';
		++start;
	}
}

void print_text(char s[])
{
	printf("%s\n", s);
}

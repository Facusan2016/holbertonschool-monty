#include "monty.h"


/**
 * check_argv - Checks if q_passed and q_expected are
 * equal, if they're not equal, prints an error and
 * exits, otherwise don't do anything.
 * @q_passed: Amount to evaluate
 * @q_expected: Amount that is expected.
 * Return: Nothing.
*/

void check_argv(int q_passed, int q_expected)
{
	if (q_passed != q_expected)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_malloc - If Null is passed to this function
 * means that an error ocurred asking for memory,
 * prints the corresponding error and
 * exits with EXIT_FAILURE
 * @pointer: Amount to evaluate
 * Return: Nothing.
*/

void check_malloc(void *pointer)
{
	if (pointer == NULL)
	{
		free_g_and_exit();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

}

/**
 * check_all_digits - Checks if all the characters in the string
 * are digits, if they're returns 0, otherwise returns 1
 * @str: String to be checked if it haves all digits.
 * Return: 0 if every character is a digit, 1 otherwise.
*/

int check_all_digits(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);

	while (str[i] == '-' || str[i] == '+' || isdigit(str[i])
	&& str[i] != '\0')
		i++;

	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

/**
 * is_blank - Checks if a line is composed of spaces and \n.
 * @line: Line to be check.
 * Return: 1 if true, 0 if false.
*/

int is_blank(char *line)
{
	int i = 0;

	while (((line != NULL && line[i] != '\0')) &&
		(line[i] == '\n' || line[i] == ' '))

		i++;

	if (line[i] == '\0')
	{
		free(g->line);
		return (1);
	} else
		return (0);
}

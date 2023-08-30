#include "monty.h"

/**
 * open_file - Opens the file named namefile,
 * also checks if namefile is NULL
 * if there's an error, prints "Error: Can't open file <@namefile>"
 * and exits with EXIT_FAILURE
 * @filename: Name of the file to be opened.
 * Return: The corresponding file descriptor on success
 * or exits otherwise.
*/

FILE *open_file(char *filename)
{
	FILE *file;

	if (!filename)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (!file)
	{
		free(g);
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * getFunc - Returns the function requested for the opcode.
 * @arr: Reference to the stack.
 * @n: Number of line where the function was executed
 * Return: Nothing.
*/

void (*getFunc(char **arr, int n))(stack_t **stack, unsigned int line_number)
{
	int count = 0;

	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{NULL, NULL}
	};

	while (ops[count].opcode != NULL &&
	strcmp(ops[count].opcode, arr[0]) != 0)
		count++;

	if (ops[count].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", n, arr[0]);
		free_stack(g->stack);
		free_g_and_exit();
		exit(EXIT_FAILURE);
	}

	return (ops[count].f);
}

/**
 * free_g_and_exit - Frees all the gloval variables.
 * Return: Nothing.
*/

void free_g_and_exit(void)
{
	free_arr_token(g->arr_token);
	free(g->line);
	fclose(g->file);
	free(g);
}

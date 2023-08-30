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
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * getFunction - Returns the function requested for the opcode.
 * @arr: Reference to the stack.
 * Return: Nothing.
*/

void (*getFunction(char **arr))(stack_t **stack, unsigned int line_number)
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

	while (ops[count].opcode != NULL && strcmp(ops[count].opcode, arr[0]) != 0)
		count++;

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


#include "monty.h"
main_t *g;

/**
 * main - Main entry point.
 * @argc: Int that counts the amount of args.
 * @argv: Array containing the args.
 * Return: Exits
*/

int main(int argc, char **argv)
{
	char *delim = " \n\t";
	unsigned int j = 1;
	stack_t *m_stack = NULL;

	g = malloc(sizeof(main_t));
	g->arr_token = NULL;
	g->file = open_file(argv[1]);
	g->line = NULL;

	check_argv(argc, 2);

	while (1)
	{
		g->line = read_line(g->file);
		if (g->line == NULL)
			break;

		if (is_blank(g->line) == 1)
		{
			j++;
			continue;
		}

		g->arr_token = tokenize(g->line, delim);
		check_malloc((void *) g->arr_token);

		g->stack = m_stack;
		getFunc(g->arr_token, j)(&m_stack, j);

		free(g->line);
		free_arr_token(g->arr_token);

		j++;
	}

	free_stack(m_stack);
	fclose(g->file);
	free(g);

}

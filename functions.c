#include "monty.h"

/**
* _push - Function to pushing a number to the stack
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (check_all_digits(g->arr_token[1]) == 1)
	{
		free_stack(*stack);
		free_g_and_exit();
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);

	} else
	{
		new = malloc(sizeof(stack_t));
		check_malloc((void *) new);

		new->n = atoi(g->arr_token[1]);

		if (*stack == NULL)
		{
			new->next = NULL;
			new->prev = NULL;
			*stack = new;

		} else
		{
			(*stack)->prev = new;
			new->next = *stack;
			new->prev = NULL;
			*stack = new;
		}
	}
}

/**
* _pall - Function to print the stack.
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iter = *stack;
	(void) line_number;

	while (iter != NULL)
	{
		printf("%i\n", iter->n);
		iter = iter->next;
	}

}

/**
* _pint - Function to print the stacktop.
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tem = *stack;

	if (*stack == NULL)
	{
		free_stack(*stack);
		free_g_and_exit();
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", tem->n);
	}

}

/**
* free_stack - Frees the stack.
* @stack: Main reference to the stack.
* Return: Nothing.
*/

void free_stack(stack_t *stack)
{
	stack_t *torem;

	while (stack != NULL)
	{
		torem = stack;
		stack = stack->next;
		free(torem);
	}
}


#include "monty.h"

/**
* _pop - Removes the top element of the stack.
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev;

	if (*stack == NULL)
	{
		free_stack(*stack);
		free_g_and_exit();
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;

	} else
	{
		prev = (*stack)->next;
		(prev)->prev = NULL;
		free(*stack);
		*stack = prev;
	}
}

/**
* _swap - Swaps the top two elements of the stack.
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *tmp1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		free_g_and_exit();
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = tmp->next;

	tmp->next = tmp1->next;
	tmp->prev = tmp1;
	tmp1->prev = NULL;
	tmp1->next = tmp;

	*stack = tmp1;
}

/**
* _add - Adds the top two elements of the stack.
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *prev;

	if (*stack == NULL || (*stack != NULL && ((*stack)->next == NULL)))
	{
		free_stack(*stack);
		free_g_and_exit();
		fprintf(stderr, "L%i>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	prev = (*stack)->next;
	prev->n += (*stack)->n;
	free(*stack);
	prev->prev = NULL;
	*stack = prev;

}

/**
* _nop - doesn't do anything.
* @stack: Main reference to the stack.
* @line_number: Line where the command is exectued.
* Return: Nothing.
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

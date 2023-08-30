#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct main_s - opcode and its function.
 * @line: Char pointer line.
 * @arr_token: Tokenized array.
 * @file: Reference to the open function.
 *
 * Description: global variables.
 */

typedef struct main_s
{
	char *line;
	char **arr_token;
	FILE *file;
} main_t;

extern main_t *g;
FILE *open_file(char *filename);
void check_argv(int q_passed, int q_expected);
void check_malloc(void *pointer);
int check_all_digits(char *str);
char **tokenize(char *str, char *delim);
void free_arr_token(char **arr);
char *read_line(FILE *file);
void (*getFunction(char **arr))(stack_t **stack, unsigned int line_number);
void free_g_and_exit(void);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _not_found(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_blank(char *line);

#endif

#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#define TOK_DELIM " \t\r\n\a"
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

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
 * struct global_vars - global variables
 * @number: number to initailise linked list with.
 * @fp: file pointer.
 * @stack: the stack.
 * @line: line containing opcodes.
 */
typedef struct global_vars
{
	int number;
	FILE *fp;
	stack_t *stack;
	char *line;
} globs;
extern globs global;

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

void _pall(stack_t **head, unsigned int line_num);
void execute_op(char *input, unsigned int line_num);
void _push(stack_t **head, unsigned int line_num);
void _pint(stack_t **head, unsigned int line_num);
void _pop(stack_t **head, unsigned int line_num);
void _swap(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void _sub(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);
void _mod(stack_t **head, unsigned int line_num);
void _nop(stack_t **head, unsigned int line_num);
void _pchar(stack_t **head, unsigned int line_num);
void _pstr(stack_t **head, unsigned int line_num);

void cleanup_exit(void);
void free_stack(stack_t *head);
void check_push(char *tok, unsigned int line_num);
char *trim_space(char *s);
int is_number(char *str);
#endif /* MONTY_H */

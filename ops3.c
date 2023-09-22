#include "monty.h"

/**
 * _mod - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _mod(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next || !head)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		cleanup_exit();
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		cleanup_exit();
	}
	top = *head;
	(*head)->next->n %= (*head)->n;
	*head = top->next;
	(*head)->prev = NULL;
	free(top);
}

/**
 * _pchar - prints the char at the top of the stack.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pchar(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !head)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		cleanup_exit();
	}
	top = *head;
	if (top->n >= 0 && top->n <= 127)
		printf("%c\n", top->n);
	else
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		cleanup_exit();
	}
}

/**
 * _pstr - prints the string starting at the stack top, followed by a \n.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pstr(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	if (!*head || !head)
	{
		printf("\n");
		return;
	}
	top = *head;
	while (top)
	{
		if (top->n > 0 && top->n <= 127)
			printf("%c", top->n);
		else
			break;
		top = top->next;
	}
	printf("\n");
}

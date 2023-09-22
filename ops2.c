#include "monty.h"

/**
 * _add - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next || !head)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		cleanup_exit();
	}
	top = *head;
	(*head)->next->n += (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * _sub - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _sub(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next || !head)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		cleanup_exit();
	}
	top = *head;
	(*head)->next->n -= (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * _div - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _div(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		cleanup_exit();
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		cleanup_exit();
	}
	top = *head;
	(*head)->next->n /= (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * _mul - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _mul(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		cleanup_exit();
	}
	top = *head;
	(*head)->next->n *= (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * _nop - here goes nothing.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _nop(stack_t **head, __attribute__((unused))unsigned int line_num)
{
	(void)head;
}

#include "monty.h"

/**
 * free_stack - frees a doubly linked list.
 * @head: the top of the stack.
 * Return: void.
 */
void free_stack(stack_t *head)
{
	stack_t *top;

	while (head)
	{
		top = head;
		head = head->next;
		free(top);
	}
}

/**
 * trim_space - removes leading and trailing whitespace from a string.
 * @s: pointer to the string.
 * Return: pointer to the trimmed string.
 */
char *trim_space(char *s)
{
	char *end;

	while (isspace((unsigned char)*s))
		s++;

	if (*s == '\0')
		return (s);

	end = s + strlen(s) - 1;
	while (end > s && isspace((unsigned char)*s))
		end--;

	*(end + 1) = '\0';
	return (s);
}

/**
 * is_number - checks if a string is a number.
 * @str: the string.
 * Return: 1 if it's a number and 0 otherwise.
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

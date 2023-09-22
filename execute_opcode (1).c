#include "monty.h"

/**
 * execute_op - checks and executes the opcode.
 * @input: the buffer containing the opcode.
 * @line_num: the line number of the opcode.
 * Return: void.
 */
void execute_op(char *input, unsigned int line_num)
{
	instruction_t ops[] = {
		{"pall", _pall}, {"push", _push}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}
	};
	char *tok;
	int i;

	input = trim_space(input);
	if (!*input || *input == '#')
		return;
	tok = strtok(input, TOK_DELIM);
	for (i = 0; i < 13; i++)
	{
		if (strcmp(tok, ops[i].opcode) == 0)
		{
			if (strcmp(tok, "push") == 0)
			{
				tok = strtok(NULL, TOK_DELIM);
				check_push(tok, line_num);
			}
			ops[i].f(&global.stack, line_num);
			return;
		}
	}
	dprintf(2, "L%u: unknown instruction %s\n", line_num, tok);
	cleanup_exit();
}

/**
 * check_push - checks if the push opcode has been used correctly.
 * @tok: the number in string.
 * @line_num: the line number of the opcode in its file.
 */
void check_push(char *tok, unsigned int line_num)
{
	if (is_number(tok))
		global.number = atoi(tok);
	else
	{
		dprintf(2, "L%u: usage: push integer\n", line_num);
		cleanup_exit();
	}
}

/**
 * cleanup_exit - frees all memory and exits with a failed stauts.
 * Return: void.
 */
void cleanup_exit(void)
{
	fclose(global.fp);
	free_stack(global.stack);
	free(global.line);
	exit(EXIT_FAILURE);
}

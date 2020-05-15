#include "monty.h"

/**
* read_file - get lines from a file
*/

void read_file(void)
{
	size_t len = 0;
	int tokn, bol = 0;
	char *command;

	while (getline(&(data()->buf), &len, data()->file) != EOF)
	{
		if (!data()->buf)
		{
			fclose(data()->file);
			errors(3, 0, NULL);
		}
		data()->line++;
/*		data()->buf = buf; */
		data()->toks = strtow(data()->buf, " \t\n");
		if (data()->toks && data()->toks[0] && data()->toks[0][0] != '#')
		{
			for (tokn = 0; data()->toks[tokn]; tokn++)
				continue;
			data()->ctok = tokn;
			command = data()->toks[0];
			(void)command;
			get_op(data()->toks[0]);
		}
		free_all(bol);
	}
	free_all(1);
	/*free_stack(&stack);*/
}

/**
* free_tok - frees an doble pointer array
* @tok: pointers array to arrays of strings
*/
void free_tok(char **tok)
{
	size_t i = 0;

	if (tok == NULL)
		return;
	for (i = 0; tok[i]; i++)
		free(tok[i]);
	free(tok);
}

/**
* get_op - selects a function to run
* according to the command
* @command: the command to search
*/
void get_op(char *command)
{
	int i = 0, bol = 1;
	instruction_t opfun[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		/*
		*{"add", op_add},
		*{"nop", op_nop},
		*{"sub", op_sub},
		*/
		{NULL, NULL},
	};

	while (opfun[i].opcode)
	{
		if (!strcmp(command, opfun[i].opcode))
		{
			opfun[i].f(&data()->stack, data()->line);
			return;
		}
		i++;
	}
	if (!opfun[i].opcode)
	{
		errors(2, data()->line, command);
		free_all(bol);
		exit(EXIT_FAILURE);
		return;
	}
}

/**
 * free_stack - frees a doble_linked_list
 * @stack: the doble_linked_list
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
* data - initializes data for monty
* Return: struct for global access
*/

data_t *data(void)
{
	static data_t global = {NULL, NULL, NULL, NULL, 0, 0, 0};

	return (&global);
}

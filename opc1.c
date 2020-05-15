#include "monty.h"

/**
* op_push - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	int bol = 1;

	if (data()->ctok < 2 || !is_number(data()->toks[1]))
	{
		errors(4, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}
	if (data()->mode)
		add_dnodeint_end(stack, atoi(data()->toks[1]));
	add_dnodeint(stack, atoi(data()->toks[1]));
}

/**
* op_pall - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
* op_pint - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
	int bol = 1;
	stack_t *node = get_dnodeint_at_index(*stack, 0);

	if (!node)
	{
		errors(5, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", node->n);

}

/**
* op_pop - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	printf("%d - %d\n", (*stack)->n, line_number);
}

/**
* op_swap - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
	printf("swap %d\n", line_number);
}

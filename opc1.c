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
	stack_t *node = get_dnodeint_at_index(*stack, 0);
	int bol = 1;

	if (!node)
	{
		errors(6, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}
/**
* op_swap - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
		errors(7, line_number, NULL);
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

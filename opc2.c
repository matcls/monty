#include "monty.h"

/**
* op_add - adds the top two elements of the stack.
* @stack: memory stack
* @line_number: command line number
*/
void op_add(stack_t **stack, unsigned int line_number)
{
	int bol = 1, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		errors(8, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	sum += (*stack)->next->n;
	op_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
* op_nop - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* op_sub - push a number to stack
* @stack: memory stack
* @line_number: command line number
*/
void op_sub(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

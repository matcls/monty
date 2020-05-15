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
* op_nop - doesn’t do anything.
* @stack: memory stack
* @line_number: command line number
*/
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* op_sub - subtracts the top element of the stack from the second top element
* @stack: memory stack
* @line_number: command line number
*/
void op_sub(stack_t **stack, unsigned int line_number)
{
	int sub, bol = 1;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		errors(9, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->n;
	sub -= (*stack)->next->n;
	sub *= -1;
	op_pop(stack, line_number);
	(*stack)->n = sub;
}


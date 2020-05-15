#include "monty.h"

/**
* op_mod - computes the rest of the division of the second top
* element of the stack by the top element of the stack.
* @stack: memory stack
* @line_number: command line number
*/
void op_mod(stack_t **stack, unsigned int line_number)
{
	int temp, bol = 1;

	if (*stack == NULL || ((*stack)->prev == NULL && (*stack)->next == NULL))
	{
		errors(13, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	if (temp == 0)
	{
		errors(14, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, line_number);
	(*stack)->n = (*stack)->n % temp;
}

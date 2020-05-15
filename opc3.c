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

/**
* op_pchar - prints the char at the top of the stack,
* followed by a new line.
* @stack: memory stack
* @line_number: command line number
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int bol = 1;

	if (!(*stack) || stack == NULL)
	{
		errors(16, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 32 || temp->n > 127)
	{
		errors(15, line_number, NULL);
		free_all(bol);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", temp->n);
}

/**
* op_pstr - prints the string starting at the top of the stack,
* followed by a new line..
* @stack: memory stack
* @line_number: command line number
*/
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if ((*stack))
	{
		while (temp->next && temp->n != 0)
		{
			if (temp->n > 32 && temp->n <= 127)
			{
				printf("%c", temp->n);
				temp = temp->next;
			}
		}
		printf("\n");
	}
	(void)line_number;
}

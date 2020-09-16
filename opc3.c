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

	if (*stack)
	{
		while (temp)
		{
			if (temp->n > 0 && temp->n <= 127)
				printf("%c", temp->n);
			else
				break;
			temp = temp->next;
		}
	}
	printf("\n");
	(void)line_number;
}

/**
* op_rotl - rotates the stack to the top.
* @stack: memory stack
* @line_number: command line number
*/
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack))
		return;

	if (*stack && (*stack)->next)
	{
		while (temp->next)
			temp = temp->next;

		temp->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next->next = NULL;
	}
	(void)line_number;
}

/**
* op_rotr - rotates the stack to the bottom.
* @stack: memory stack
* @line_number: command line number
*/
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	if (!current)
	{
		free_dlistint(*stack);
		errors(3, line_number, NULL);
	}

	if (!(*stack))
		return;

	while (temp->next)
		temp = temp->next;

	current->n = temp->n;
	current->prev = NULL;
	temp->prev->next = NULL;
	free(temp);

	current->next = (*stack);
	(*stack)->prev = current;
	(*stack) = current;

	(void)line_number;
}

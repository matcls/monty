#include "monty.h"

/**
* errors- prints an error acording to a code
* @errc: error code
* @line: line with the error
* @str: string with the error
*/
void errors(int errc, int line, char *str)
{
	if (errc == 0)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (errc == 1)
		fprintf(stderr, "Error: Can't open file %s\n", str),
	exit(EXIT_FAILURE);
	if (errc == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	if (errc == 3)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (errc == 4)
		fprintf(stderr, "L%d: usage: push integer\n", line);
	if (errc == 5)
		fprintf(stderr,	"L%d: can't pint, stack empty\n", line);
	if (errc == 6)
		fprintf(stderr,	"L%d: can't pop an empty stack\n", line);
}
/**
* is_number - checks if a string is a number
* @str: string to check
* Return: 1 on succes 0 otherwise
*/
int is_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

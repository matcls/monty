#include "monty.h"

/**
* main - starting point for monty interpreter
* @argc: arguments count
* @argv: pointer to arrary of arguments
*
* Return: on succes EXIT_SUCCES, on failure EXIT_FAILURE
*/

int main(int argc, char *argv[])
{
	/* FILE *file = NULL; */
	int bol = 1;

	if (argc != 2)
		errors(0, 0, NULL);
	/*file = fopen(argv[1], "r");*/
	data()->file = fopen(argv[1], "r");
	if (!data()->file)
	{
		free_all(bol);
		errors(1, 0, argv[1]);
	}
	/*data()->file = file;*/
	read_file();
	if (data()->file)
	{
		fclose(data()->file);
		data()->file = NULL;
	}
	return (EXIT_SUCCESS);
}

/**
* free_all - free all memory used for monty interpreter
* @bol: boolean true variable
*/
void free_all(int bol)
{
	if (data()->buf)
	{
		free(data()->buf);
		data()->buf = NULL;
		free_tok(data()->toks);
		data()->toks = NULL;
	}
	if (bol)
	{
		if (data()->stack)
		{
			free_dlistint(data()->stack);
			data()->stack = NULL;
		}
		if (data()->file)
		{
			fclose(data()->file);
			data()->file = NULL;
		}
	}
}

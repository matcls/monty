#include "monty.h"
/**
 * _delimiters - finds characters in the command line to break args
 *
 * @c: character to be compared
 * @delimiter: array of characters to be compared
 * Return: on succes 1, else 0
 */
int _delimiters(char c, char *delimiter)
{
	for (; *delimiter;)
	{
		if (*delimiter++ == c)
			return (1);
	}
	return (0);
}
/**
 * count_letters - counts the number of letters of a word
 * @str: string.
 * @delimiter: string containing characters that indicate limits
 * Return: number of letters of a word
 */
int count_letters(char *str, char *delimiter)
{
	int index = 0, letters = 0;

	while (str[index] && !_delimiters(str[index], delimiter))
	{
		letters++;
		index++;
	}

	return (letters);
}

/**
 * count_words - Counts the number of words in a given string
 * @str: given string
 * @delimiter: string containing characters that indicate limits
 * Return: number of words in str.
 */
int count_words(char *str, char *delimiter)
{
	int index, words = 0, length = 0;

	for (index = 0; str[index]; index++)
		length++;

	for (index = 0; index < length; index++)
	{
		if (!_delimiters(str[index], delimiter) &&
			(_delimiters(str[index + 1], delimiter) || !str[index + 1]))
		{
			words++;
			index += count_letters(str + index, delimiter);
		}
	}

	return (words);
}

/**
 * strtow - splits a string into words
 * @data: pointer to data structure
 * @delimiter: string containing characters that indicate limits
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str, char *delimiter)
{
	char *s = NULL, **toks = NULL;
	int index = 0, words, w, letters, l;

	 s = str;

	if (s == NULL || s[0] == 0)
		return (NULL);

	words = count_words(s, delimiter);
	if (!words)
		return (NULL);

	toks = malloc(sizeof(char *) * (words + 1));
	if (!toks)
		return (NULL);

	for (w = 0; w < words; w++)
	{
		while (_delimiters(s[index], delimiter))
			index++;

		letters = count_letters((s + index), delimiter);

		toks[w] = malloc((letters + 1) * sizeof(char));
		if (toks[w] == NULL)
		{
			while (w--)
				free(toks[w]);
			free(toks);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
			toks[w][l] = s[index++];

		toks[w][l] = 0;
	}
	toks[w] = NULL;
	return (toks);
}

#include "monty.h"

/**
 * tokenize - This function takes str as an input and returns
 * an array with each word of this string. it uses malloc for
 * returning the right amount of memory, so it must be liberated after
 * being used. It also freeds str.
 * @delim: Delimiter that we're going to use to tokenize.s
 * @str: String to split into words.
 * Return: A pointer to an array of words or NULL if failed.
*/

char **tokenize(char *str, char *delim)
{
	char **res;
	char *token, *cpy_str;
	int count = 0, i = 0;

	if (str == NULL)
		return (NULL);

	cpy_str = strdup(str);
	token = strtok(cpy_str, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		count++;
	}
	free(cpy_str);
	res = malloc(sizeof(char **) * (count + 1));

	if (res == NULL)
		return (NULL);
	cpy_str = strdup(str);
	token = strtok(cpy_str, delim);
	for (i = 0; token != NULL && i < count; i++)
	{
		res[i] = strdup(token);
		token = strtok(NULL, delim);

		if (res[i] == NULL)
		{
			for (; i >= 0; i--)
				free(res[i]);

			free(res);
			return (NULL);
		}
	}
	free(cpy_str);
	res[i] = NULL;
	return (res);
}

/**
 * free_arr_token - This functions takes an allocated array of words,
 * frees the memory of each word and then the memory of the array.
 * @arr: Array that contains the words.
 * Return: Always void.
*/

void free_arr_token(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		free(arr[i++]);

	free(arr);
}

/**
 * read_line - This function reads a line from the passed input.
 * it allocates memory, so it have to be freeded.
 * @file: File to be readed.
 * Return: A pointer to a allocated string.
*/

char *read_line(FILE *file)
{
	char *buff = NULL;
	ssize_t bytes_read;
	size_t size = 0;

	bytes_read = getline(&buff, &size, file);

	if (bytes_read == -1)
	{
		free(buff);
		return (NULL);
	}

	return (buff);
}

#include "main.h"

/**
 * tokenize_input - tokenizes the user input
 * @buffer: User input buffer
 *
 * Return: A linked list with the buffer tokens
 * On failure, return NULL
 */
char **tokenize_input(char *buffer)
{
	char *token; 
	char *delimeter = " \t\n:";
	int size = 120;
	int i;
	char **tokens;

	token = strtok(buffer, delimeter);
	if (token == NULL)
	{
		free(buffer);
		return (NULL);
	}
	tokens = (char **)malloc(size * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	tokens[0] =_strdup(token);
	i = 1;
	token = strtok(NULL, delimeter);
	while(token != NULL)
	{
		tokens[i++] = _strdup(token);
		token = strtok(NULL, delimeter);
	}
	tokens[i] = NULL;
	free(buffer);
	return (tokens);
	
}	

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
	
	if (buffer[0] == '\n' || buffer[0] == '\0')
	{
		return (NULL);
	}
	token = strtok(buffer, delimeter);
	tokens = (char **)malloc(size * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	i = 0;
	while(token != NULL)
	{
		tokens[i++] = _strdup(token);
		token = strtok(NULL, delimeter);
	}
	if (i == 0)
	{
		free(tokens);
		return (NULL);
	}
	tokens[i] = NULL;
	return (tokens);
	
}	

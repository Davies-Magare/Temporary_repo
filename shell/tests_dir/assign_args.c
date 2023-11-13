#include "main.h"

/**
 * assign_args - Assigns components from a linked list to an array
 * @argv: An array of pointers
 * @head: A pointer to a linked ist
 *
 * Return: The initialized array of pointers
 */
char **assign_args(tokens_t *head, char **args)
{
	tokens_t *temp;
	int i;
	
	temp = head;
	for (i = 0; temp != NULL; i++)
	{
		args[i] = strdup(temp->token);
		temp = temp->next;
	}
	args[i] = NULL;
	return (args);
}
/**
 * exit_cleanup - Cleans up after exiting the shell
 * @argv: An array of pointers
 * @head: A pointer to a linked list
 *
 * Return: Nothing
 */
void exit_cleanup(char *argv[])
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
	argv = NULL;
}

	
	

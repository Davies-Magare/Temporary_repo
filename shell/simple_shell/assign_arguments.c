#include "main.h"

/**
 * assign_args - Assigns components from a linked list to an array
 * @argv: An array of pointers
 * @head: A pointer to a linked ist
 *
 * Return: The initialized array of pointers
 */
char **assign_args(tokens_t *head)
{
	tokens_t *temp;
	int i;
	int arg_count;
	char **args;
	
	temp = head;
	arg_count = 0;
	for (i = 0; temp != NULL; i++)
	{
		arg_count++;
		temp = temp->next;
	}
	args = (char **)malloc(sizeof(char *) * (arg_count + 1));
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

	
	

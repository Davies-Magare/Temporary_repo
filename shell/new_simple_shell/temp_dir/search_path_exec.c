#include "main.h"

/**
 * search_command - searches the path and executes if found
 * @head_dir: A linked list of directories in the PATH
 * @head: A linked list of the user input tokens
 * 
 * Return: Nothing
 */
char *search_command(tokens_t *head_dir, char *command, char *path)
{
	char *search_path = NULL;
	tokens_t *temp;

	temp = head_dir;
	while(temp != NULL)
	{
		search_path = (char *) malloc(strlen(temp->token) + strlen(command) + 2);
		if (search_path == NULL)
		{
			return (NULL);
		}
		strcpy(search_path, temp->token);
		strcat(search_path, "/");
		strcat(search_path, head->token);
		if ((access(search_path, X_OK) == 0))
		{
			printf(" path found in acc: %s\n", search_path);
			break;
		}
		temp = temp->next;
		free(search_path);
		search_path = NULL;
	}
	free(path);
	free_list(head_dir);
	if (search_path)
		return (search_path);
	perror(head->token);
	return (NULL);
}
/**
 * execute_command - executes the command found in path
 * @head: A linked list with the user tokens
 * @command: The full command path found in PATH
 * @env: An array of the environment variables
 * 
 * Return: 0 on failure, 1 on success
 */
int execute_command(tokens_t *head, char *command, char **env)
{
	char **args = NULL;
	pid_t pid;
	int status;

	if (!command)
	{
		free_list(head);
		return (0);
	}
	args = initialize_array(head, args);
	free_list(head);
	free(args[0]);
	args[0] = command;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(errno);
	}
	else if (pid == 0)
	{
		execve(args[0], args, env);
		perror(args[0]);
		free_array(args);
		args = NULL;
		exit(errno);
	}
	else
	{
		wait(&status);
		if (args)
		{
			free_array(args);
			args = NULL;
		}
	}
	return (status);
}
/**
 * initialize_array - initializes an array of pointers
 * @head: A linked list with user tokens
 * @args: An NULL initialized double pointer
 *
 * Return: A dynamically allocated array of pointers
 */
char **initialize_array(tokens_t *head, char **args)
{
	int token_count, i;
	tokens_t *temp;

	token_count = 0;
	for(temp = head; temp != NULL; temp = temp->next)
		token_count++;
	args = (char **)malloc(sizeof(char *) * (token_count + 1));
	for (temp = head, i = 0; temp != NULL; temp = temp->next)
	{
		args[i++] = strdup(temp->token);
		temp = temp->next;
	}
	args[i] = NULL;
	return (args);
}

















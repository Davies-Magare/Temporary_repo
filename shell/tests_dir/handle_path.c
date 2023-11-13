#include "main.h"

/**
 * handle_path - returns the full path of the command
 * @command: The command input from the user
 * 
 * Return: The full path of the command
 */
char *handle_path(char *command)
{
	char *path, *copy_path, *path_to_return, *path_tok;
	char *error = " :command not found\n";
	path = getenv("PATH");
	copy_path = strdup(path);

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
		{
			free(copy_path);
			return (command);
		}
		else
		{
			free(command);
			free(copy_path);
			return (NULL);
		}
	}
	path_tok = strtok(copy_path, ":");
	while(path_tok != NULL)
	{
		path_to_return = (char *)malloc(strlen(path_tok) + strlen(command) + 2);
		strcpy(path_to_return, path_tok);
		strcat(path_to_return, "/");
		strcat(path_to_return, command);
		if (access(path_to_return, X_OK) == 0)
		{
			free(command);
			free(copy_path);
			return (path_to_return);
		}
		free(path_to_return);
		path_tok = strtok(NULL, ":");
	}
	free(copy_path);
	write(2, command, strlen(command));
	write(2, error,   strlen(error));
	free(command);
	return (NULL);
}











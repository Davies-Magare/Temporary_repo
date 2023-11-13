#include "main.h"

/**
 * full_command - searches for the full command
 * @head: The entry into a linked list
 *
 * Return: 1 if the command was found and run
 * returns 0 if otherwise
 */
int full_command(char **args, char **envp)
{
        pid_t pid;
	char *full_path = NULL; 
	char *job_path;
	char *path, *cpy_path;
	int status;
	extern char **environ;
	
	path = find_path(environ);
	job_path = _strdup(path);
	cpy_path = job_path;
	while (1)
	{
        	if (access(args[0], X_OK) == 0)
                	break;
		full_path = search_command(args[0], job_path);
		if (full_path == NULL)
                {
			print_error(args[0]);
                        free_array(args);
                        free(cpy_path);
                        return (0);
                }
		free(args[0]);
		args[0] = NULL;
		args[0] = full_path;
		break;
	}
        /*execute */
        pid = fork();
        if (pid < 0)
        {
                return (0);
        }
        else if (pid == 0)
        {
                if ((execve(args[0], args, envp) == -1))
                return (0);
        }
        else
	{
                wait(&status);
		if (WIFEXITED(status))
			global_exit_status = (WEXITSTATUS(status));
	}
        free_array(args);
	free(cpy_path);
	return (1);
}
/**
 * free_array - frees an array of pointers
 * @array: An array of pointers
 *
 * Return: Nothing.
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}
/**
 * print_error - prints error on stderr in case the command is not found
 * @mode: The shell mode i.e 1 for interactive and 0 for non_interactive
 * @program: The name of the program
 *
 * Return: Nothing
 */ 

void print_error(char *program)
{
	char *str_prog = "./hsh: 1: ";
	char *end_str = ": not found\n";

	write(2, str_prog, strlen(str_prog));
	write(2, program, strlen(program));
	write(2, end_str, strlen(end_str));
}


















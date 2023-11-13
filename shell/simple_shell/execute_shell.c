#include "main.h"

/**
 * execute_shell - executes user arguments
 * @argv: The commandline arguments
 * @envp: An array of environment variables
 *
 * Return: The exit status of the child process
 */
int execute_shell(char **args, char **envp)
{
	pid_t pid;
	int exit_status, status;
	pid_t ret_wait;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		ret_wait = waitpid(-1, &status, 0);
		if (ret_wait == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_status = WTERMSIG(status);
	}
	return (exit_status);
}

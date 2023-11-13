#include <stdio.h>
#include <unistd.h>
#include "main.h"
int main(void)
{
	char str[] = "/bin/ls -l /home/vagrant/shell";
	char **tokens;
	pid_t pid;
	int status, i;

	tokens = tokenizer(str);
	if (tokens)
	{	
		for (i = 0; i < 5; i++)
		{
			pid = fork();
			if (pid > 0)
			{
				waitpid(-1, &status, 0);
				if (!WIFEXITED(status))
				{
					if (WIFSIGNALED(status))
					{
						printf("Process terminated by signal %i\n", WTERMSIG(status));
						kill(pid, SIGTERM);
					}

				}		
			}
		
			else if (pid == 0)
			{
				execve(tokens[0], tokens, NULL);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				perror("fork:");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}

			


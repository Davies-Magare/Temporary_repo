#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int __attribute__((unused)) argc, char *argv[])
{
	
	pid_t pid;
	int status;

	
	argv[0] = "echo";
	argv[1] = '"qwerty"';
	argv[2] = "|";
	argv[3] = "/bin/sh";

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		execve(argv[0], argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (0);
}


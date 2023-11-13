#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid, parent_pid, ret_fork;
	
	ret_fork = fork();
	if (ret_fork > 0)
	{
		printf("I'm the parent!\n");
		pid = getpid();
		printf("And my PID is %i\n", pid);
	}
	else
	{
		printf("Hello, I'm the child!\n");
		parent_pid = getppid();
		printf("And my parent's pid is %i\n", parent_pid);
	}
	return (0);
}
	

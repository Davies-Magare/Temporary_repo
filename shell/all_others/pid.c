#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid, pid_prt;

	pid = getpid();
	pid_prt = getppid();
	printf("%u\n", pid);
	printf("pid_prt = %u\n", pid_prt);
	return (0);
}


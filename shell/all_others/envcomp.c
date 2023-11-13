#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	extern char **environ;

	printf("%p\n%p\n", envp, environ);
	return (0);
}

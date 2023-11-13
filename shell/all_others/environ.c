#include <stdio.h>

int main(void)
{
	extern char **environ;

	int i;

	i = 0;
	while(environ[i] != NULL)
	{
		printf("%s\n", environ[i++]);
	}
	return (0);
}

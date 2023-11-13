#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int main(void)
{
	char **args = NULL;
	size_t size;
	char *buffer = NULL;
	ssize_t getline_ret;
	int i;

	while (1)
	{
		printf("sabes?$ ");
		getline_ret = getline(&buffer, &size, stdin);
		if (getline_ret == -1)
		{
			break;
		}
		args  = tokenize_input(buffer);
		if (args == NULL)
		{
			printf("We have to go on\n");
			continue;
		}
		if ((strcmp(args[0], "exit") == 0))
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			free(buffer);
			break;
		}
		for (i = 0; args[i]; i++)
		{
			printf("%s\n", args[i]);
		}

		for(i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	return (0);
}

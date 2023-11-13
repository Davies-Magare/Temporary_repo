#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	size_t n;
	ssize_t getline_ret;
	FILE *stream;
	char *buffer = NULL;
	char *tokens[1024];
	char *token;
	int i;

	if (argc < 2)
	{
		fprintf(stdout, "Usage: <file>\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while((getline_ret = getline(&buffer, &n, stream)) != EOF)
	{
		token = strtok(buffer, " ");
		while(token != NULL)
		{
			tokens[i++] = strdup(token);
			token = strtok(NULL, " ");
		}
	}
	tokens[i] = NULL;
	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("%s\n", tokens[i]);
	}
	for (i = 0;  tokens[i] != NULL; i++)
		free(tokens[i]);
	fclose(stream);
	free(buffer);
	return (0);
}

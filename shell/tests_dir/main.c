#include "main.h"

int main(void)
{
	char buffer[100];
	tokens_t *head, *temp;
	char *copy_buf;
	char **tokens;
	int i;
	char *cpy_arg;
	
	printf("Enter a string> ");
	scanf("%s", buffer);
	copy_buf = strdup(buffer);
	head = tokenize_input(copy_buf);
	temp = head;
	
	while (temp != NULL)
	{
		printf("%s\n", temp->token);
		temp = temp->next;
	}
	tokens = (char **) malloc(6 * sizeof(char *));
	tokens = assign_args(head, tokens);
	cpy_arg = strdup(tokens[0]);
	tokens[0] = handle_path(tokens[0]);
	if (!tokens[0])
	{
		tokens[0] = cpy_arg;
		printf("Your command does not exist\n");
		printf("I'll give you this instead: \n");
		for (i = 1; tokens[i] != NULL; i++)
			printf("%s\n", tokens[i]);
	}
	else
	{
		printf("Your command exists!");
		printf("Here is your path: \n");
		for (i = 0; tokens[i] != NULL; i++)
			printf("%s\n", tokens[i]);
		free(cpy_arg);
	}
		
	exit_cleanup(tokens);
	free_list(head);
	free(copy_buf);
	return (0);
}
	 

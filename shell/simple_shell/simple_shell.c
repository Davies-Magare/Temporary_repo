#include "main.h"

/**
 * main - driver function
 * @argc: The argument count to main
 * @argv: An array of string arguments to main
 * @envp: An array of string environment variables
 * 
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **envp)
{
	char *buffer = NULL;
	size_t count;
	char *prompt = "$ "; 
	char *copy_buf;
	char **args;
	int getline_ret, ret_exec;
	int terminal = isatty(STDIN_FILENO);
	tokens_t *head;
	
	while(1)
	{
		if (terminal)
			write(1, prompt, 2);
		getline_ret = getline(&buffer, &count, stdin);
		if (getline_ret == -1)
		{
			perror("getline");
			getline_free(buffer, getline_ret);
			break;
		}
		printf("%s\n", buffer);
		copy_buf = check_buffer(buffer);
		if (copy_buf[0] == '\n')
			continue;
		head = tokenize_input(copy_buf);
		args = assign_args(head);
		free_list(head);
		if (strcmp(args[0], "exit") == 0)
		{
			exit_cleanup(args);
			exit(0);
		}
		args[0] = handle_path(args[0]);
		if (!args[0])
		{
			exit_cleanup(args);
			continue;
		}
		ret_exec = execute_shell(args, envp);
		printf("%u\n", ret_exec);		
		exit_cleanup(args);
		free(buffer);
			
	}
	return (0);
}
/**
 * getline_free - frees the buffer incase getline function fails
 * @buffer: The buffer
 * @count: The number of characters read by getline
 
 * Return: Nothing
 */
void getline_free(char *buffer, ssize_t count)
{

	if (count == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_buffer - locates the first non_space character in input
 * @buffer: The buffer containing user input
 * 
 * Return: Nothing
 */
char *check_buffer(char *buffer)
{
	int i;
	
	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] != ' ')
			break;
	if (buffer[i] == '\0')
		return (NULL);
	return (buffer + i);
}
		

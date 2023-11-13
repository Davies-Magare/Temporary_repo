#include "main.h"

/**
 * main - driver function for the code
 * @argc: The argument count
 * @argv: An array of string arguments to main

 * Return: Always 0 (Success)
 */
int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[], char **envp)
{
        ssize_t getline_ret;
        char *buffer = NULL, *prompt = "$ ";
        size_t size;
	char **args;
	int mode = isatty(0);
	int ret_exec;

        while (1)
        {
                if (mode == 1)
                        write(1, prompt, strlen(prompt));
                getline_ret = getline(&buffer, &size, stdin);
                if (getline_ret == -1)
                {
			break;
                }
                args = tokenize_input(buffer);
		if (args == NULL)
		{
			errno = 0;
			continue;
		}
		if (_strcmp(args[0], "env") == 0)
		{
			errno = 0;
			free_array(args);
			print_env();
			continue;
		}
		if (_strcmp(args[0], "exit") == 0)
		{
			free_array(args);
			free(buffer);
			exit(global_exit_status);  
		}
		ret_exec = full_command(args, envp); 
		if (ret_exec)
			errno = 0;
		else
			errno = 127;
	}
	free(buffer);
	return (errno);
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

/**
 * print_env - prints the environment
 * @envp: An array of the environment variables
 *
 * Return: Nothing
 */
void print_env(void)
{
	int i;
	extern char **environ;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}

































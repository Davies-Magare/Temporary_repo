#include "main.h"

/**
 * search_command - searches the path and executes if found
 * @head_dir: A linked list of directories in the PATH
 * @head: A linked list of the user input tokens
 *
 * Return: Nothing
 */
char *search_command(char *command, char *path)
{
        char *search_path = NULL;
	char *path_tok;
	struct stat st;
	
	path_tok = strtok(path, ":");
        while(path_tok != NULL)
        {
                search_path = (char *) malloc(strlen(path_tok) + strlen(command) + 2);
                if (search_path == NULL)
                {
                        return (NULL);
                }
                strcpy(search_path, path_tok);
                strcat(search_path, "/");
                strcat(search_path, command);
		printf("The search path is %s\n", search_path);
                if ((stat(search_path, &st) == 0))
                {
                        printf("Path found in acc: %s\n", search_path);
                        break;
                }
                free(search_path);
                search_path = NULL;
		path_tok = strtok(NULL, ":");
        }
        if (search_path != NULL) 
                return (search_path);
        return (NULL);
}
/**
 * execute_command - executes a command path found in PATH
 * @head: A linked list of the commandline arguments
 * 
 * Return: 0 on failure, 1 on Success
 */
int execute_command(tokens_t *head, char *command, char **env)
{
        char **args = NULL;
        pid_t pid;
        int status;
	
	head->token = command;
        args = initialize_array(head, args);
        pid = fork();
        if (pid == -1)
        {
                perror("fork");
                exit(errno);
        }
        else if (pid == 0)
        {
                execve(args[0], args, env);
                perror(args[0]);
                free_array(args);
                args = NULL;
                exit(errno);
        }
        else
        {
                wait(&status);
                if (args)
                {
                        free_array(args);
                        args = NULL;
                }
        }
        return (status);
}
/**
 * initialize_array - initializes an array of pointers
 * @head: A linked list with user tokens
 * @args: An NULL initialized double pointer
 *
 * Return: A dynamically allocated array of pointers
 */
char **initialize_array(tokens_t *head, char **args)
{
        int token_count, i;
        tokens_t *temp;

        token_count = 0;
        for(temp = head; temp != NULL; temp = temp->next)
                token_count++;
        args = (char **)malloc(sizeof(char *) * (token_count + 1));
        for (temp = head, i = 0; temp != NULL; temp = temp->next, i++)
        {
                args[i] = strdup(temp->token);
                temp = temp->next;
        }
        args[i] = NULL;
        return (args);
}

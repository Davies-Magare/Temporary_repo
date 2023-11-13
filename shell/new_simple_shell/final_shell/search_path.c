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
               _strcpy(search_path, path_tok);
                _strcat(search_path, "/");
                _strcat(search_path, command);
                if ((stat(search_path, &st) == 0))
                {
                        break;
                }
                free(search_path);
                search_path = NULL;
                path_tok = strtok(NULL, ":");
        }
        if (search_path != NULL)
	{
                return (search_path);
	}
        return (NULL);
}

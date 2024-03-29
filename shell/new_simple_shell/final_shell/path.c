#include "main.h"

/**
 * find_path - searches for the command in PATH
 * @envp: The list of environment variables
 * @head: A pointer to a linked list
 *
 * Return: 1 on Success, Otherwise return 0
 */
char *find_path(char **envp)
{
        char *path;
        int i;

        for (i = 0; envp[i] != NULL; i++)
                if ((_strstr(envp[i], "PATH")) && envp[i][4] == '=')
                {
                        path = (envp[i]) + _strlen("PATH") + 1;
                        break;
                }
        return (path);
}


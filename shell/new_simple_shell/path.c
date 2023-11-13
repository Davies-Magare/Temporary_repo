#include "main.h"

/**
 * find_path - searches for the command in PATH
 * @envp: The list of environment variables
 * @head: A pointer to a linked list
 * 
 * Return: 1 on Success, Otherwise return 0
 */
tokens_t *find_path(char **envp)
{
	char *path;
	tokens_t *head_dir;
	int i;

	for (i = 0; envp[i] != NULL; i++)
		if (strstr(envp[i], "PATH"))
		{
			path = strdup(envp[i]);
			break;
		}
	path += 5;
	printf("%s\n", path);
	head_dir = tokenize_directory(path);
	return (head_dir);
}

/**
 * tokenize_input - tokenizes the user input
 * @path: The environment PATH variable
 *
 * Return: A linked list with the path tokens
 * On failure, return NULL
 */
tokens_t *tokenize_directory(char *path)
{
	char *token; 
	char *delimeter = ":";
	tokens_t *head, *to_fill, *new_node; 
	
	if (path[0] == '\0')
		return (NULL);
	token = strtok(path, delimeter);
	if (token != NULL)
	{
		head = (tokens_t *) malloc(sizeof(tokens_t));
		if (head == NULL)
			return (NULL);
		head->token = strdup(token);
		head->next = NULL;
	}
	to_fill = head;
	token = strtok(NULL, delimeter);
	while(token != NULL)
	{
		new_node = (tokens_t *)malloc(sizeof(tokens_t));
		if (new_node == NULL)
			return (NULL);
		new_node->token = token;
		new_node->next = NULL;
		to_fill->next = new_node;
		to_fill = new_node;
		token = strtok(NULL, delimeter);
	}
	return (head);
}
/**
 * free_list_dir - frees a linked list of directories
 * @head_dir: A linked list
 * 
 * Return: Nothing
 */
void free_list_dir(tokens_t *head_dir)
{
	tokens_t *temp;
	
	temp = head_dir;
	while(temp != NULL)
	{
		head_dir = head_dir->next;
		free(temp->token);
		free(temp);
		temp = head_dir;
	}
}
		














	

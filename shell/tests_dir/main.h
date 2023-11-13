#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct tokens{
	char *token;
	struct tokens *next;
}tokens_t;
tokens_t *tokenize_input(char *buffer);
void free_list(tokens_t *head);
char **assign_args(tokens_t *head, char **args);
void exit_cleanup(char *argv[]);
char *handle_path(char *command);

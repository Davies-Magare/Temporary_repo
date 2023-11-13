#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#define BUFSIZE 1024

typedef struct tokens
{ 
	char *token;
	struct tokens *next;
}tokens_t;
tokens_t *tokenize_input(char *buffer);
void getline_free(char *buffer, ssize_t count);
char *check_buffer(char *buffer);
char **assign_args(tokens_t *head);
void exit_cleanup(char *argv[]);
int execute_shell(char **args, char **envp);
char *handle_path(char *command);
void free_list(tokens_t *head);
#endif

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
char **tokenize_input(char *buffer);
char *check_buffer(char *buffer);
int full_command(char **args, char **envp);
void free_array(char **array);
int global_exit_status;
char *find_path(char **envp);
char *search_command(char *command, char *path);
void print_env(void);
void print_error(char *program);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);



#endif

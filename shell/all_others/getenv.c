#include <stdio.h>
#include <string.h>
char *_getenv(const char *name);
char *strcpy_delim(char *dest, char *src, char delim);
int _strcmp(const char *str1, const char *str2);
int main(void)
{
	char user[75];
	char *variable;

	printf("Enter the name of the variable> ");
	scanf("%s", user);
	variable = _getenv(user);
	if (!variable)
		printf("Variable does not exist\n");
	else
		printf("%s\n", variable);
	return (0);
}
char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char cpy[75];
	

	for (i = 0; environ[i]; i++)
	{
		strcpy_delim(cpy, environ[i], '=');
		if ((_strcmp(cpy, name)) == 0)
			return (environ[i]);
	}
	if (environ[i] == NULL)
		return (NULL);
}

char *strcpy_delim(char *dest, char *src, char delim)
{
	int i;

	for (i = 0; src[i] != delim; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int _strcmp(const char *str1, const char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			break;
	}
	if (!str1[i] && !str2[i])
		return (0);
	else if (!str1[i] || !str2[i])
	{
		if (str1[i])
			return (1);
		else if (str2[i])
			return (-1);
	}
	if (str1[i] > str2[i])
		return (1);
	else if (str2[i] > str1[i])
		return (-1);
}
	





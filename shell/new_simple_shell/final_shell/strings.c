#include "main.h"

/**
 * strcpy - copies a string pointed by src, including the terminating
 * null byte, to the buffer pointed by dest
 * @dest: A pointer to a buffer into which the string will be copied.
 * @src: A pointer to the string to be copied.
 *
 * Return: A pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of the string
 * @str: A string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len, i;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * strcat - concantenates two strings
 * @dest: The string into which src is appended.
 * @src: The string to be appended to dest.
 *
 * Return: A pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, len;

	len = 0;
	for (i = 0; dest[i] != '\0'; i++)
		len++;
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0 in case the strings are equal, 
 * 1 if str1 is greater than string 2
 * otherwise -1 is returned
 */
int _strcmp(char *str1, char *str2)
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
	return (-1);
}
















#include "main.h"
 /**
 * _strdup - returns a pointer to space in memory containing
 * a copy of the string  given as parameter
 * @str: A pointer to a string
 *
 * Return: On success, a pointe to the duplicated string in memory
 * Otherwise a pointer to null is returned.
 */
char *_strdup(char *str)
{
        char *strp;

        if (str == NULL)
                return (NULL);
        strp = malloc(_strlen(str) + 1);
        if (strp == NULL)
                return (NULL);
        _strcpy(strp, str);
        return (strp);
}

/**
 * _strstr - searches for a needle in a haystack
 * @haystack: The string to scan
 * @needle: The substring to search for
 *
 * Return: A pointer to the start of the substring
 * Otherwise NULL is returned
 */

char *_strstr(char *haystack, char *needle)
{
   int i, j, k;
    
    if (!*needle)
        return (haystack);
    else if (!*haystack)
        return (NULL);
    for (i = 0; haystack[i]; i++)
    {
            if (haystack[i] != *needle)
                continue;
            for (k = i, j = 0; j < _strlen(needle) && haystack[k] &&  
			haystack[k] == needle[j]; k++, j++){}
            if (j == _strlen(needle))
                return (&haystack[i]);
    }
    return (NULL);
}


 

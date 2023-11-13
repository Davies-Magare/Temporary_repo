#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *variable;

	variable = getenv("PATH");
	printf("%s\n", variable);
	return (0);
}

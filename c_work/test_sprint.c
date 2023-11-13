#include <stdio.h>

int main(void)
{
	int i, j, k;
	char s[30];

	i = 1;
	j = 2;
	k = 3;
	sprintf(s, "[%d][%d][%d]", i, j, k);
	printf("%s\n", s);
	return (0);
}

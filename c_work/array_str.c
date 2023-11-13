#include <stdio.h>

#define NUM_PEOPLE 25
#define NAME_LEN 25

int main(void)
{
	char names[NUM_PEOPLE][NAME_LEN];
	int i, values;
	
	printf("Enter the words\n> ");
	values = 0;
	for (i = 0; i < NUM_PEOPLE && names[i - 1][0] != '9'; i++)
	{
		scanf("%s", names[i]);
	}
	values = i;

	for (i = 0; i < values - 1; i++)
		printf("%s ", names[i]);
	printf("\n");
	return (0);
}

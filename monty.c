#include "monty.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (open(av[1], O_RDONLY) == -1)
	{
		printf("can't open file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}

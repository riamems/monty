#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - Entry point of the monty program
* @argc: Number of command line arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	size_t size;
	char *content = NULL;
	ssize_t read_line = 0;
	unsigned int counter = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&content, &size, file)) > 0)
	{
		bus.content = strdup(content);
		if (bus.content == NULL)
		{
			fprintf(stderr, "Error: strdup failed\n");
			free_stack(stack);
			fclose(file);
			free(content);
			return (EXIT_FAILURE);
		}
		counter++;
		execute(content, &stack, counter, file);
		free(bus.content);
	}
	free_stack(stack);
	fclose(file);
	free(content);
	return (EXIT_SUCCESS);
}

#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @head: Head of the stack
 * @counter: Line number
 * Return: Nothing
 */
void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

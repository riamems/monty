#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @head: Head of the stack
 * @counter: Line number
 * Return: Nothing
 */
void swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, result;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	result = h->n;
	h->n = h->next->n;
	h->next->n = result;
}

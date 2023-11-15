#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: Head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *result;

	while (head)
	{
		result = head->next;
		free(head);
		head = result;
	}
	head = NULL;
}

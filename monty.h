#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: Value
 * @file: Pointer to monty file
 * @content: Line content
 * @lifi: flag change stack <-> queue
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **head, unsigned int counter);
void pall(stack_t **head, unsigned int counter);
void pint(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void addqueue(stack_t **head, int value);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void stack(stack_t **head, unsigned int counter);
#endif

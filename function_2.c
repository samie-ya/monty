#include "monty.h"

/**
* nop - does nothing
*
* @stack: pointer to the beginning of stack
*
* @line_number: the line number of the bytecode
*
* Return: Nothing
*/

void nop(stack_t **stack, unsigned int __attribute__((__unused__))line_number)
{
	(void)stack;
}

/**
* add - adds the first two top stacks
*
* @stack: pointer to the beginning of the stack
*
* @line_number: the line number of the byte code
*
* Return: Nothing
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n = head->n + head->next->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

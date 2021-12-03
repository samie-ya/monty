#include "monty.h"

/**
* mod - the rest of the division of the two top element
*
* @stack: pointer to the beginning of the stack
*
* @line_number: line number of the bytecode
*
* Return: Nothing
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n = head->next->n % head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

/**
* pchar - prints the ASCII value of the interger
*
* @stack: pointer to the beginning of the stack
*
* @line_number: line number of the bytecode
*
* Return: Nothing
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%c\n", head->n);
}

/**
* pstr - uses the values of the stack starting from
*        the top to char to form string
*
* @stack: pointer to the beginning of stack
*
* @line_number: line number of the bytecode
*
* Return: Nothing
*/

void pstr(stack_t **stack, unsigned int __attribute__((__unused__))line_number)
{
	stack_t *head = *stack;

	while (head != NULL)
	{
		if ((head->n <= 0 || head->n > 127))
			break;
		dprintf(STDOUT_FILENO, "%c", head->n);
		head = head->next;
	}
	dprintf(STDOUT_FILENO, "\n");
}

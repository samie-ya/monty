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

/**
* sub - subtracts the first element from the second
*
* @stack: pointer to the beginning of the stack
*
* @line_number: the line number of the byte code
*
* Return: Nothing
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n = head->next->n - head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

/**
* mul - multiplies the first two element from the stack
*
* @stack: pointer to the beginning of the stack
*
* @line_number: the line number of the byte code
*
* Return: Nothing
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n = head->next->n * head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

/**
* divide - divides the second element from the first
*
* @stack: pointer to the beginning of the stack
*
* @line_number: the line number of the byte code
*
* Return: Nothing
*/

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n = head->next->n / head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

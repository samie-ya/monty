#include "monty.h"

/**
* no_of_argc - checks the number of arguments
*
* @ac: number of commandline arguments
*
* Return: Nothing
*/

void no_of_argc(int ac)
{
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
* free_list - frees the stack
*
* @stack: pointer to the beginning of the stack
*
* Return: Nothing
*/

void free_list(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

/**
* _isdigit - finds a number in a string
*
* @str: tring to be searched
*
* Return: 1 if found, else 0
*/

int _isdigit(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
	}
	return (0);
}

/**
* is_not_digit - checks if str contains non digit values
*
* @str: the string to be checked
*
* Return: 1 if found
*/

int is_not_digit(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}

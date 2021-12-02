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
	int i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '-')
			continue;
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
	}
	return (0);
}

/**
* _istag - to check if there is a hashtag
*
* @str: string to be checked
*
* Return: 1 if found else 0
*/

int _istag(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
	}
	return (0);
}

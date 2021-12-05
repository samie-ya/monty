#include "monty.h"

/**
* find_code - matches the opcode with arguments in the file
*
* @cmd: the arguments in file
*
* @stack: pointer to beginning of stack
*
* @line_number: line number in byte code
*
* Return: Always 0
*/

int find_code(char *cmd, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t code[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{"pstr", pstr},
		{"pchar", pchar},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
		};
	i = 0;
	while (code[i].opcode != NULL)
	{
		if (strcmp(code[i].opcode, cmd) == 0)
		{
			code[i].f(stack, line_number);
			break;
		}
	i++;
	}
	if (code[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
* main - function to open a file and read and interprete
*
* @ac: number of command line arguments
*
* @av: value of command line arguments
*
* Return: Always 0
*/

int main(int ac, char **av)
{
	FILE *ptr;
	size_t n = 0;
	int line_number = 0;
	char *cmd = NULL, *value = NULL, *line = NULL;
	stack_t *stack = NULL;

	no_of_argc(ac);
	ptr = fopen(av[1], "r");
	if (ptr == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &n, ptr)) != -1)
	{
		line_number++;
		cmd = strtok(line, " \n\t");
		value = strtok(NULL, " \n\t");
		if (cmd == NULL || cmd[0] == '#')
			continue;
		else if (_isdigit(value) == 1 && strcmp("push", cmd) == 0)
			push(&stack, atoi(value));
		else if (strcmp("push", cmd) != 0)
			find_code(cmd, &stack, line_number);
		else if (value == NULL || (is_not_digit(value) == 1))
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_list(stack);
	fclose(ptr);
	return (0);
}

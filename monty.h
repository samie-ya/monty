#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *
 * @n: integer
 *
 * @prev: points to the previous element of the stack (or queue)
 *
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 *
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 *
 * @opcode: the opcode
 *
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 *
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* helper Functions */

void no_of_argc(int ac);
int _isdigit(char *str);
void free_list(stack_t *stack);
int is_not_digit(char *str);

/* opcode Functions */

void pall(stack_t **stack, unsigned int __attribute__
((__unused__))line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int __attribute__((__unused__))line_number);
stack_t *push(stack_t **stack, int num);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int __attribute__
((__unused__))line_number);
void rotl(stack_t **stack, unsigned int __attribute__
((__unused__))line_number);
void rotr(stack_t **stack, unsigned int __attribute__
((__unused__))line_number);

/* interpreting functions */

int find_code(char *cmd, stack_t **stack, unsigned int line_number);

#endif

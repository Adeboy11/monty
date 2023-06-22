#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structurefor stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @line: line content
 * @lifo: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct buff_t
{
	char *line;
	int lifo;
	char *arg;
	FILE *file;
} buff_f;
extern buff_f buff;

void push(stack_t **head, unsigned int no);
void pall(stack_t **head, unsigned int no);
void pint(stack_t **head, unsigned int no);
int execute(char *content, stack_t **head, unsigned int index, FILE *file);
void free_stack(stack_t *head);
void pop(stack_t **head, unsigned int index);
void swap(stack_t **head, unsigned int index);
void add_c(stack_t **head, unsigned int index);
void nop(stack_t **head, unsigned int index);
void sub(stack_t **head, unsigned int index);
void div_c(stack_t **head, unsigned int index);
void mul(stack_t **head, unsigned int index);
void mod(stack_t **head, unsigned int index);
void pchar(stack_t **head, unsigned int index);
void pstr(stack_t **head, unsigned int index);
void rotl(stack_t **head, unsigned int index);
void rotr(stack_t **head, __attribute__((unused)) unsigned int index);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void queue(stack_t **head, unsigned int index);
void stack(stack_t **head, unsigned int index);

#endif

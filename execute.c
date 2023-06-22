#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @index: index no
 * @file: poiner to monty file
 * @line: line
 * Return: none
 */
int execute(char *line, stack_t **stack, unsigned int index, FILE *file)
{
	instruction_t opst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add_c", add_c}, {"nop", nop}, {"sub", sub},
		{"div_c", div_c}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {"queue", queue},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *ops;

	ops = strtok(line, " \n\t");
	if (ops && ops[0] == '#')
		return (0);
	buff.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && ops)
	{
		if (strcmp(ops, opst[i].opcode) == 0)
		{	opst[i].f(stack, index);
			return (0);
		}
		i++;
	}
	if (ops && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", index, ops);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

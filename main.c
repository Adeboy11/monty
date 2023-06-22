#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

buff_f buff = {NULL, 0, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file arguments
 * Return: 0 if successive
 */
int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	size_t siz = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int index = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	buff.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &siz, file);
		buff.line = line;
		index++;
		if (read_line > 0)
			execute(line, &stack, index, file);
		free(line);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

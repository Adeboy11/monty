#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @index: line no
 * Return: none
*/
void push(stack_t **head, unsigned int index)
{
	int n, j = 0, flag = 0;

	if (buff.arg)
	{
		if (buff.arg[0] == '-')
			j++;
		for (; buff.arg[j] != '\0'; j++)
		{
			if (buff.arg[j] > 57 || buff.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", index);
			fclose(buff.file);
			free(buff.line);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(buff.arg);
	if (buff.lifo == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

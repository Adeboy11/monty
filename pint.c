#include "monty.h"
/**
 * pint - prints the top
 * @head: stack head
 * @index: line no
 * Return: none
*/
void pint(stack_t **head, unsigned int index)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

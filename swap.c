#include "monty.h"
/**
 * swap - swap top two ele of the stack.
 * @head: stack head
 * @index: line number
 * Return: none
*/
void swap(stack_t **head, unsigned int index)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

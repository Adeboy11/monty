#include "monty.h"
/**
 * add - add the top the two elements.
 * @head: stack head
 * @index: index no
 * Return: none
 */
void add_c(stack_t **head, unsigned int index)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

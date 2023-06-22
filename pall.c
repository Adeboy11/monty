#include "monty.h"
/**
 * pall - display the stack
 * @head: stack head
 * @index: argument not used
 * Return: none
*/
void pall(stack_t **head, unsigned int index)
{
	stack_t *h;
	(void)index;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

#include "monty.h"
/**
 * pstr - display the string starting at the top of the stack
 * @head: stack head
 * @index: line no
 * Return: none
*/
void pstr(stack_t **head, unsigned int index)
{
	stack_t *h;
	(void)index;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

#include "monty.h"
/**
 * pop - displays the top
 * @head: stack head
 * @index: line no
 * Return: none
*/
void pop(stack_t **head, unsigned int index)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

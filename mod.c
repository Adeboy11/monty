#include "monty.h"
/**
 * mod - computes the modulus of the
 * second element by the
 * top element of the stack
 * @head: stack head
 * @index: number no
 * Return: none
 */
void mod(stack_t **head, unsigned int index)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

#include "monty.h"
/**
  *sub- sustract from the stack
  *@head: stack head
  *@index: line no
  *Return: no return
 */
void sub(stack_t **head, unsigned int index)
{
	stack_t *aux;
	int mpx, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", index);
		fclose(buff.file);
		free(buff.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	mpx = aux->next->n - aux->n;
	aux->next->n = mpx;
	*head = aux->next;
	free(aux);
}

#include "monty.h"
/**
  *rotl- rotates the stack to the top
  *@head: stack head
  *@index: line no
  *Return: none
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int index)
{
	stack_t *tmp = *head;
	stack_t *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

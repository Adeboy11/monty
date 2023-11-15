#include "monty.h"

/**
  *rotr- rotates to the bottom
  *@head: stack head
  *@index: line no
  *Return: none
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int index)
{
	stack_t *cmp;

	cmp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cmp->next)
	{
		cmp = cmp->next;
	}
	cmp->next = *head;
	cmp->prev->next = NULL;
	cmp->prev = NULL;
	(*head)->prev = cmp;
	(*head) = cmp;
}

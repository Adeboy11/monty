#include "monty.h"
/**
 * addnode - add node to the stack
 * @head: head
 * @n: new value
 * Return: none
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_nodes, *auxes;

	auxes = *head;
	new_nodes = malloc(sizeof(stack_t));
	if (new_nodes == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (auxes)
		auxes->prev = new_nodes;
	new_nodes->n = n;
	new_nodes->next = *head;
	new_nodes->prev = NULL;
	*head = new_nodes;
}

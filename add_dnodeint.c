#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list
 * @head: point to the pointer to the head of the list
 * @n: integer to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node_ptr = malloc(sizeof(stack_t));

	if (!node_ptr)
		error_malloc();
	node_ptr->prev = NULL;
	node_ptr->next = *head;
	node_ptr->n = n;
	if (*head)
		(*head)->prev = node_ptr;
	*head = node_ptr;

	return (*head);
}
/**
 * free_stack_t - frees the doubly linked list
 * @head: head of the list
 *
 * Return: no return
 */
void free_stack_t(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}

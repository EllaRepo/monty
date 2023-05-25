#include "monty.h"

/**
 * _mod -  computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;
	int i;

	(void)line_number;
	msg = ": can't mod, stack too short\n";
	for (h = *head, i = 0; h != NULL; h = h->next, i++)
		;
	if (i < 2)
		get_error(-1, msg);
	if ((*head)->n == 0)
	{
		msg = ": division by zero\n";
		get_error(-1, msg);
	}
	h = (*head)->next;
	h->n %= (*head)->n;
	_pop(head, line_number);
}

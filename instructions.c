#include <string.h>
#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @head: head of the linked list
 * @line_number: line number
 *
 * Return: None
 */
void _push(stack_t **head, unsigned int line_number)
{
	char *msg, *arg;
	int i;
	(void)line_number;

	msg = ": usage: push integer\n";

	if (mn_parm.arg == NULL)
		get_error(-1, msg);
	arg = mn_parm.arg;
	for (i = 0; arg[i] != '\0'; i++)
	{
		if (!_isdigit(arg[i]) && arg[i] != '-')
			get_error(-1, msg);
	}
	add_dnodeint(head, atoi(arg));
}

/**
 * _pall - prints all values on the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

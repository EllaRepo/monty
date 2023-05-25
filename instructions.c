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
/**
 * _pint -  the value at the top of the stack, followed by a new line
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _pint(stack_t **head, unsigned int line_number)
{
	char *msg;

	(void)line_number;
	msg = ": can't pint, stack empty\n";
	if (!(*head))
		get_error(-1, msg);
	printf("%d\n", (*head)->n);
}
/**
 * _pop - removes the top element of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;

	(void)line_number;
	msg = ": can't pop an empty stack\n";
	if (!(*head))
		get_error(-1, msg);
	h = *head;
	*head = (*head)->next;
	free(h);
}
/**
 * _swap - swaps the top two elements of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;
	int i;

	(void)line_number;
	msg = ": can't swap, stack too short\n";
	for (h = *head, i = 0; h != NULL; h = h->next, i++)
		;
	if (i < 2)
		get_error(-1, msg);
	h = *head;
	*head = (*head)->next;
	h->next = (*head)->next;
	h->prev = *head;
	(*head)->next = h;
	(*head)->prev = NULL;
}

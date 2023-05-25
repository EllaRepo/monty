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
/**
 * _pchar -  prints the char at the top of the stack, followed by a new line
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	char *msg;

	(void)line_number;
	msg = ": can't pchar, stack empty\n";
	if (!(*head))
		get_error(-1, msg);
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		msg = ": can't pchar, value out of range\n";
		get_error(-1, msg);
	}
	printf("%c\n", (*head)->n);
}
/**
 * _pstr - prints the string starting at the top of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h && h->n > 0 && h->n < 128)
	{
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
/**
 * _rotl - rotates the stack to the top
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *h, *h2;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
		return;
	h = (*head)->next;
	for (h2 = *head; h2->next != NULL; h2 = h2->next)
		;
	h->prev = NULL;
	h2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = h2;
	*head = h;
}
/**
 * _rotr - rotates the stack to the mottom
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
		return;
	h = (*head)->next;
	for (h = *head; h->next != NULL; h = h->next)
		;
	h->prev->next = NULL;
	h->prev = NULL;
	h->next = *head;
	(*head)->prev = h;
	*head = h;
}

#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;
	int i;

	(void)line_number;
	msg = ": can't add, stack too short\n";
	for (h = *head, i = 0; h != NULL; h = h->next, i++)
		;
	if (i < 2)
		get_error(-1, msg);
	h = (*head)->next;
	h->n += (*head)->n;
	_pop(head, line_number);
}
/**
 * _nop - deosn't do anything
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
/**
 * _sub - subtracts the top element of the stack from the second
 *        top element of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;
	int i;

	(void)line_number;
	msg = ": can't sub, stack too short\n";
	for (h = *head, i = 0; h != NULL; h = h->next, i++)
		;
	if (i < 2)
		get_error(-1, msg);
	h = (*head)->next;
	h->n -= (*head)->n;
	_pop(head, line_number);
}
/**
 * _div - divides the second top element of the stack by the
 *        top element of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;
	int i;

	(void)line_number;
	msg = ": can't div, stack too short\n";
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
	h->n /= (*head)->n;
	_pop(head, line_number);
}
/**
 * _mul - multiplies the second top element of the stack with the
 *        top element of the stack
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	char *msg;
	int i;

	(void)line_number;
	msg = ": can't mul, stack too short\n";
	for (h = *head, i = 0; h != NULL; h = h->next, i++)
		;
	if (i < 2)
		get_error(-1, msg);
	h = (*head)->next;
	h->n *= (*head)->n;
	_pop(head, line_number);
}

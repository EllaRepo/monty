#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	mn_parm.data_format = 1;
}

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @head: head of the linked list
 * @line_number: line numbers
 *
 * Return: None
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	mn_parm.data_format = 0;
}


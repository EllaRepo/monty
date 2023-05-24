#include "monty.h"

/**
 * error_malloc - print malloc error
 *
 * Return: None
*/
void error_malloc(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_mn_parm();
	exit(EXIT_FAILURE);
}
/**
 * get_error - prints error message to stderr
 * @eval: error value
 * @str: error message
 *
 * Return: None
*/
void get_error(int eval, char *str)
{
	switch (eval)
	{
		case -1:
			dprintf(2, "USAGE: monty file\n");
			break;
		case 0:
			dprintf(2, "Error: Can't open file %s\n", eval, str);
			break;
		default:
			dprintf(2, "L%u: unknown instruction %s\n", mn_parm.line_num, str);
			break;
	}
	free_mn_parm();
	exit(EXIT_FAILURE);
}

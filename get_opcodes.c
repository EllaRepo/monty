#include <string.h>
#include "monty.h"

/**
 * get_func - retrieves a function based on the given opcode
 * @opcode: interpreter parameter structure
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{NULL, NULL}
	};
	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}

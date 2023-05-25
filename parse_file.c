#include "monty.h"

/**
 * tokenize - tokenizes a string
 *  @str: input string
 *
 * Return: The resulting array of tokens
*/
char **tokenize(char *str)
{
	char **tokens = malloc(sizeof(char *) * strlen(str));
	char *token;
	int i = 0;

	token = strtok(str, " \t\0");

	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		i++;
		token = strtok(NULL, " \t");
	}
	tokens = realloc(tokens, sizeof(char *) * (i + 1));
	tokens[i] = NULL;

	return (tokens);
}
/**
 * execute_opcode - executes opcode
 *
 * Return: void
 */
void execute_opcode(void)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = get_func(mn_parm.opcode);
	if (!f)
		get_error(mn_parm.line_num, mn_parm.opcode);
	f(&mn_parm.stack, mn_parm.line_num);
}
/**
 * _parse_file - executes command
 *
 * Return: void
 */
void _parse_file(void)
{
	mn_parm.opcode = strtok(mn_parm.line, " \t\n");
	if (mn_parm.opcode == NULL)
		return;
	mn_parm.arg = strtok(NULL, " \t\n");
	execute_opcode();
}
/**
 * parse_file - parse file
 *
 * Return: void
 */
void parse_file(void)
{
	int i, j;
	char t, buff[BUFSIZE], *line;

	i = 0;
	while ((j = read(mn_parm.fd, &t, 1)) > -1)
	{
		buff[i] = t;
		if (t == '\n' || j == 0)
		{
			buff[i] = '\0';
			line = buff;
			mn_parm.line = _strdup(line);
			mn_parm.line_num += 1;
			_parse_file();
			free(mn_parm.line);
			i = -1;
		}
		if (j == 0)
			break;
		i++;
	}
	close(mn_parm.fd);
	free_stack_t(mn_parm.stack);
}

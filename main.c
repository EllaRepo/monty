#include <stdio.h>
#include "monty.h"

mn_t mn_parm;
/**
 * free_mn_parm - frees the mn_parm variables
 *
 * Return: None
 */
void free_mn_parm(void)
{
	free_stack_t(mn_parm.stack);
	free(mn_parm.buff);
	fclose(mn_parm.fd);
}
/**
 * init - initializes global parameters
 * @argv: argument vector
 *
 * Return: None
*/
void init(char **argv)
{
	mn_parm.stack = NULL;
	mn_parm.arg = NULL;
	mn_parm.filename = argv[1];
	mn_parm.line_num = 1;
	mn_parm.fd =  fopen(argv[1], "r");
	if (mn_parm.fd == NULL)
		get_error(0, mn_parm.filename);
}
/**
 * main - the main monty code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	size_t size;
	ssize_t i;
	FILE *fd = NULL;
	char *line;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	init(argv);
	size = BUFSIZE;
	i = getline(&mn_parm.buff, &size, fd);
	while (i != -1)
	{
		line = strtok(mn_parm.buff, " \t\n");
		if (line)
		{
			f = get_func(line);
			if (!f)
				get_error(mn_parm.line_num, line);
			mn_parm.arg = strtok(NULL, " \t\n");
			f(&mn_parm.stack, mn_parm.line_num);
		}
		i = getline(&mn_parm.buff, &size, fd);
		mn_parm.line_num++;
	}
	free_mn_parm();

	exit(EXIT_SUCCESS);
}

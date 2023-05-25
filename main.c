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
	free(mn_parm.line);
	free(mn_parm.arg);
	close(mn_parm.fd);
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
	mn_parm.line = NULL;
	mn_parm.line_num = 0;
	mn_parm.fd = open(mn_parm.filename, O_RDONLY);
	if (mn_parm.fd == -1)
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
	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	init(argv);
	parse_file();
	exit(EXIT_SUCCESS);
}

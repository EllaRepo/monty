#include "monty.h"

/**
 * error_malloc - print malloc error
 *
 * Return: None
*/
void error_malloc(void)
{
	char *msg;

	msg = "Error: malloc failed\n";
	write(STDERR_FILENO, msg, strlen(msg));
	free_mn_parm();
	exit(EXIT_FAILURE);
}
/**
 * invalid_arg - gets error related with invalid arg
 * @err_line_num: error line number
 * @msg: error message
 *
 * Return: error string
*/
char *invalid_arg(int err_line_num, char *msg)
{
	char *error, *lnum;
	char buffer[33];

	lnum = itoa(err_line_num, buffer);
	error = malloc(sizeof(char) * (strlen(msg) + strlen(lnum)
		+ 2));
	if (!error)
		error_malloc();
	strcpy(error, "L");
	strcat(error, lnum);
	strcat(error, msg);
	strcat(error, "\0");
	return (error);
}
/**
 * err_file - gets error related with opeining file
 * @filename: file name
 *
 * Return: error string
*/
char *err_file(char *filename)
{
	char *error, *msg;

	msg = "Error: Can't open file ";
	error = malloc(sizeof(char) * (strlen(msg) + strlen(filename) + 2));
	if (!error)
		error_malloc();
	strcpy(error, msg);
	strcat(error, filename);
	strcat(error, "\n\0");
	return (error);
}
/**
 * err_opcode - gets error related with opeining file
 * @err_line_num: error line number
 * @opcode: opcode
 *
 * Return: error string
*/
char *err_opcode(int err_line_num, char *opcode)
{
	char *error, *msg, *lnum;
	char buffer[33];

	lnum = itoa(err_line_num, buffer);
	msg = ": unknown instruction ";
	error = malloc(sizeof(char) * (strlen(msg) + strlen(lnum)
		+ strlen(opcode) + 3));
	if (!error)
		error_malloc();
	strcpy(error, "L");
	strcat(error, lnum);
	strcat(error, msg);
	strcat(error, opcode);
	strcat(error, "\n\0");
	return (error);
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
	char *error;

	switch (eval)
	{
		case -1:
			error = invalid_arg(mn_parm.line_num, str);
			break;
		case 0:
			error = err_file(str);
			break;
		default:
			error = err_opcode(eval, str);
			break;
	}

	write(STDERR_FILENO, error, strlen(error));
	free(error);
	free_mn_parm();
	exit(EXIT_FAILURE);
}

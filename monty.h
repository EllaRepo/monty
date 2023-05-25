#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct mn_s - a struct that holds interpreter parameters
 * @stack: doubly linked list representation of a stack (or queue)
 * @arg: splited opcodes from file
 * @buff: bufferr used for getline
 * @filename: file name passed as input
 * @line_num: the current opcode line number
 * @fd: file discriptor
 */
typedef struct mn_s
{
	stack_t *stack;
	char *arg;
	char *buff;
	char *filename;
	unsigned int line_num;
	FILE *fd;
} mn_t;

extern mn_t mn_parm;
/*main*/
void free_mn_parm(void);

void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number);
/* Doubly linked list*/
stack_t *add_dnodeint(stack_t **head, const int n);
void free_stack_t(stack_t *);
void free_stack_t(stack_t *);
/* Error*/
void error_malloc(void);
char *err_file(char *filename);
char *err_opcode(int err_line_num, char *opcode);
void get_error(int eval, char *str);
/*instructions*/
void _push(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
/*string*/
char *itoa(unsigned int num, char *str);
#endif
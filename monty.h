#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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
 *struct globalvar_s - will be used as an global variable
 *@fp: pointer to the file to open
 *@buffer: holds the command for each line of input
 *@array: strings that hold the command
 *@data: data inthe node
 *Description: to pass variables in all files in repo
 */
typedef struct globalvar_s
{
	FILE *fp;
	char *buffer;
	char *array;
	int data;
} globalvar_t;

/*opcodes*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);

/*checks & errors*/
void invalid_error(int argc);
void open_error(char **argv);
void line_checker(ssize_t line);
void unknown_opcode_error(unsigned int line_number);
void check_opcode (int checker, unsigned int line_number, stack_t *head);
void malloc_error(void);

/*free*/
void free_stack(stack_t *head);
void free_buffer(void);

/*main functions*/
char *tokenize(char *buffer);
int main(int argc, char *argv[]);

#endif

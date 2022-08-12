#include "monty.h"

/**
 *invalid_error - will print a message if no file or more than 1 is given
 *@argc: argument count
 *Return: void, error
 */
void invalid_error(int argc)
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
}

/**
 *open_error - will print message if file is not able to open
 *@argv: argument vector
 *Return: void, error
 */
void open_error(char **argv)
{
	globalvar_t *glob = NULL;

	if (glob->fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 *line_checker - will see if the monty file was opened successfully
 *@line: number of lines in the file
 *Return: void, success or failure
 */
void line_checker(ssize_t line)
{
	globalvar_t *glob = NULL;

	if (line < 0)
	{
		free(glob->buffer);
		fclose(glob->fp);
		exit(0);
	}
}

/**
 *unknown_opcode_error - will print message if opcode is not found
 *@line_number: where the invalid instruction is
 *Return: void, error
 */
void unknown_opcode_error(unsigned int line_number)
{
	globalvar_t *glob = NULL;

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, glob->array);
	exit(EXIT_FAILURE);
}

/**
 *malloc_error - will print message if there is no space to malloc
 *Return: void, error
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

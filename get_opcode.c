#include "monty.h"

/**
 *get_opcode - will match an opcode with its respective function
 *@opcode: the opcode to match command
 *Return: a pointer to the respective function
 */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_functs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcode_functs[i].opcode; i++)
	{
		if (strcmp(opcode, opcode_functs[i].opcode) == 0)
			return (opcode_functs[i].f);
	}
	return (NULL);
}

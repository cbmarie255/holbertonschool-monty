#include "monty.h"

/**
 *pint - will print the value at the top of the stack
 *@stack: pointer to the stack
 *@line_number: line number to report
 *Return: void, success or failure
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

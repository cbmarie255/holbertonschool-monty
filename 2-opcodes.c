#include "monty.h"

/**
 *pop - will remove the top element of a stack
 *@stack: pointer to the stack
 *@line_number: given line number for error
 *Return: void, success or failure
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *topElement = *stack;
	stack_t *temp;

	if (topElement == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = topElement->next;
	free(topElement);
	*stack = temp;
	topElement = *stack;
	if (topElement != NULL)
	{
		topElement->prev = NULL;
	}
}

#include "monty.h"

/**
 *swap - swaps the top two elements of the stack
 *@stack: pointer to the stack
 *@line_number: line number
 *Return: void, success or failure
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *secondNode;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_buffer(top);
		exit(EXIT_FAILURE);
	}
	if (top != NULL && top->next != NULL)
	{
		secondNode = top->next;
		temp = top->n;
		top->n = secondNode->n;
		secondNode->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_buffer(top);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

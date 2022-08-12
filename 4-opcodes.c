#include "monty.h"

/**
 *add - will add the top two elements of the stack
 *@stack: pointer to the stack
 *@line_number: line number
 *Return: void, success or failure
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *secondNode;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_buffer(head);
		exit(EXIT_FAILURE);
	}
	secondNode = head->next;
	secondNode->n = (secondNode->n) + (head->n);
	pop(stack, line_number);
}

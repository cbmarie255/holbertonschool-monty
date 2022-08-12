#include "monty.h"

/**
 *push - will implement push, pushes an element to the stack
 *@stack: pointer to the stack
 *@line_number: line number on the command line
 *Return: void, success or failure
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *topNode;
	globalvar_t *glob = NULL;
	int i;

	topNode = malloc(sizeof(stack_t));
	if (topNode == NULL)
	{
		free_buffer();
		free_stack(*stack);
		malloc_error();
	}
	for (i = 0; glob->array[i] != '\0'; i++)
	{
		if ((isdigit(glob->array[i]) == 0) && (glob->array[i] != '-'))
		{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
		}
	}
	if ((*stack) != NULL)
		(*stack)->prev = topNode;
	topNode->n = atoi(glob->array);
	topNode->next = (*stack);
	topNode->prev = NULL;
	(*stack) = topNode;
}

/**
 *pall - will implement pall, prints all the values on the stack from the top
 *@stack: pointer to the stack
 *@line_number: line number on the command line
 *Return: void, success or failure
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

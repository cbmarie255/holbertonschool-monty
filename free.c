#include "monty.h"

/**
 *free_stack - will free the stack
 *@head: pointer to the head
 *Return: void, just freeing
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 *free_buffer - will free the buffer and close the stream pointing to fp
 *@head: pointer to the stack
 *Return: void, just freeing
 */
void free_buffer(stack_t *head)
{

	free_stack(head);
	if (glob.buffer != NULL)
		free(glob.buffer);
	if (glob.fp != NULL)
		fclose(glob.fp);
}

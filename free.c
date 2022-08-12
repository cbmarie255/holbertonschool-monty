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
 *Return: void, just freeing
 */
void free_buffer(void)
{
	globalvar_t *glob = NULL;

	free(glob->array);
	fclose(glob->fp);
}

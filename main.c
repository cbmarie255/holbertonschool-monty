#include "monty.h"

/**
 *tokenize - will break stdin into tokens
 *@buffer: buffer to temporalily hold input and output
 *Return: the token
 */
char *tokenize(char *buffer)
{
	char *token;

	token = strtok(buffer, " \t\n");
	if (token == NULL)
		return (NULL);
	glob.array = strtok(NULL, " \t\n");
	return (token);
}

/**
 *main - will read the Monty file and execute respective opcode
 *@argc: argument count
 *@argv: argument vector
 *Return: 0 for success or error message for failure
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	unsigned int count = 0;
	size_t buffsize;
	void (*checker)(stack_t **stack, unsigned int line_number);
	char *opcode;
	ssize_t line;

	invalid_error(argc);
	glob.fp = fopen(argv[1], "r");
	open_error(argv);
	line = getline(&glob.buffer, &buffsize, glob.fp);
	line_checker(line);
	while (line > 0)
	{
		count++;
		opcode = glob.array;
		opcode = tokenize(glob.buffer);
		if (opcode == NULL)
		{
			line = getline(&glob.buffer, &buffsize, glob.fp);
			continue;
		}
		checker = get_opcode(opcode);
		if (checker == NULL)
		{
			unknown_opcode_error(count);
			free_buffer(head);
			exit(EXIT_FAILURE);
		}
		checker(&head, count);
	}
	free_buffer(head);
	free_stack(head);
	return (0);
}

#include "monty.h"
/**
 * get_function - gets function
 *
 *@opcode: type specifier
 * Return: Function or NULL
 */
int (*get_function(char *opcode))(stack_t **, unsigned int)
{

	int j = 0;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (instruction[j].opcode != NULL)
	{
		if (strcmp(instruction[j].opcode, opcode) == 0)
		{
			return (instruction[j].f);
		}
		j++;
	}
	return (NULL);
}

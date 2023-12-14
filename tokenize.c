#include "monty.h"
/**
 * tokenizer - tokenizes line
 *@line: argument
 *@delim: delimiter
 *
 * Return: number of words
 */
size_t tokenizer(char *line,char *delim)
{
	size_t words_count = 0;

	if (strtok(line, " "))
	{
		++words_count;
	}
	while (strtok(NULL, " "))
	{
		++words_count;
	}
	return (words_count);
}
/**
 * word_list - lists
 *@line: string
 *@delim: delimiter
 *
 * Return: array of ptr
 */
char **word_list(char *line)
{
	char **opcode = NULL;
	size_t opcode_i = 0;
	size_t opcode_s = 0, line_i;
	size_t line_s = strlen(line);
	char prev_char;

	opcode_s = tokenizer(line, " ");
	if (opcode_s > 0)
	{
		opcode = malloc(sizeof(char *) * (opcode_s + 1));

		if (opcode == NULL)
		{
			printf("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		prev_char = '\0';
		for (line_i = 0; line_i < line_s; ++line_i)
		{
			if (line[line_i] != '\n' && prev_char == '\0')
			{
				opcode[opcode_i] = line + line_i;
				++opcode_i;
			}
			prev_char = line[line_i];
		}
		opcode[opcode_i] = NULL;
		printf("Tokens in word_list:\n");
        	for (size_t i = 0; opcode[i] != NULL; ++i)
        	{
            	printf("[%zu]: %s\n", i, opcode[i]);
        	}
	}
	return (opcode);
}


#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);

	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		word_list(line);
	}
	free(line);
	fclose(file);
}

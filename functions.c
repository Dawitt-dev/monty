#include "monty.h"

stack_t *stack = NULL;


stack_t *push(int n)
{
	stack *new_node = malloc(sizeof(stack_t));
	
	if(new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed \n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = stack;

	if(stack != NULL)
	{
		(*head)->prev = new_node;

	}

	stack = new_node;

	return new_node;
}


/**
 * pall - prints all elements of stack
 */
void pall(void)
{
	stack_t *current = stack;

	while(current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

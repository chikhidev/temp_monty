#include "monty.h"
/**
 * free_stack - Frees memory in stack
 * @head: Head of the list
 * Return: Void - Nothing
 **/

void free_stack(stack_t **head)
{
	stack_t *curr;
	stack_t *stack_head;

	stack_head = *head;

	while (stack_head)
	{
		curr = stack_head;
		stack_head = stack_head->next;
		free(curr);
	}
}

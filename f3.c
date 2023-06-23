#include "monty.h"

/**
* swap - Swaps the top two elements of the stack.
* @head: Head of the stack
* @line: Number of the line
* Return: Void - Nothing
**/
void swap(stack_t **head, unsigned int line)
{
int tmp;
if (head == NULL || *head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}

tmp = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = tmp;
}

/**
* nop - Doesn't do anything.
* @head: Head of the stack
* @line: Number of the line
* Return: Void - Nothing
**/
void nop(stack_t **head, unsigned int line)
{
(void)head;
(void)line;
}

#include "monty.h"

/**
* add - Adds the top two elements of the stack.
* @head: Head of the stack
* @line: Number of the line
* Return: Void - Nothing
*/
void add(stack_t **head, unsigned int line)
{
int add_elem;

/* Verify if the stack contains less than two elements */
if (!head || !(*head) || !(*head)->next)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line);
exit(EXIT_FAILURE);
}

add_elem = (*head)->n;
add_elem += (*head)->next->n;
pop(head, line);
(*head)->n = add_elem;
}

/**
* sub - Subtracts the top element of the stack from the second
* top element of the stack.
* @head: Head of the stack
* @line: Number of the line
* Return: Void - Nothing
*/
void sub(stack_t **head, unsigned int line)
{
/* Verify if the stack contains less than two elements */
if (!head || !(*head) || !(*head)->next)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line);
exit(EXIT_FAILURE);
}

(*head)->next->n -= (*head)->n;
(*head) = (*head)->next;
free((*head)->prev);
(*head)->prev = NULL;
}

/**
* mul - Multiplies the second top element of the stack with
* the top element of the stack.
* @head: Head of the stack
* @line: Number of the line
* Return: Void - Nothing
*/
void mul(stack_t **head, unsigned int line)
{
if (!head || !(*head) || !(*head)->next)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line);
exit(EXIT_FAILURE);
}

(*head)->next->n *= (*head)->n;
(*head) = (*head)->next;
free((*head)->prev);
(*head)->prev = NULL;
}

/**
* _div - Divides the second top element of the stack by the top element
* of the stack.
* @head: Head of the stack
* @line: Number of the line
* Return: Void - Nothing
*/
void _div(stack_t **head, unsigned int line)
{
if (!head || !(*head) || !(*head)->next)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line);
exit(EXIT_FAILURE);
}

if ((*head)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line);
exit(EXIT_FAILURE);
}

(*head)->next->n /= (*head)->n;
(*head) = (*head)->next;
free((*head)->prev);
(*head)->prev = NULL;
}

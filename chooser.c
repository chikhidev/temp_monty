#include "monty.h"

/**
 * chooser - Selects the appropriate function based on the given token.
 * @head: Pointer to the head of the stack
 * @token: Instruction token
 * @line: Line number of the instruction
 *
 * Return: Void - Nothing
 **/

void chooser(stack_t **head, char *token, unsigned int line)
{
instruction_t selector[] = {
{"pall", pall},
{"push", push},
{"pint", pint},
{"swap", swap},
{"add", add},
{"nop", nop},
{"pop", pop},
{"sub", sub},
{"mul", mul},
{"div", _div},
{NULL, NULL}
};

int travel = 0;

while (travel < 10)
{
if (strcmp(selector[travel].opcode, token) == 0)
{
selector[travel].f(head, line);
return;
}
travel++;
}
if (token[0] != '#')
{
fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
exit(EXIT_FAILURE);
}
}

#include "monty.h"

/**
* main - Main function
* @argc: Arguments counter
* @argv: Arguments vector
* Return: Default return value
**/
int main(int argc, char *argv[])
{
char *lineptr = NULL;
unsigned int counter = 0;
stack_t *head = NULL;
ssize_t read_file;
size_t bufsize;
FILE *fl;
char *tokens;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

fl = fopen(argv[1], "r");
if (!fl)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

while ((read_file = _getline(&lineptr, &bufsize, fl)) != -1)
{
counter++;
tokens = strtok(lineptr, LIMITER);
if (!tokens)
continue;

chooser(&head, tokens, counter);
}

free(lineptr);
free_stack(&head);
fclose(fl);
return (EXIT_SUCCESS);
}

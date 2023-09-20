#include "simple_shell.h"

char *read_line(void)
{
    char *line;
    size_t n;
    int i;

    line = NULL;
    n = 0;

    promptt();
    i = getline(&line, &n, stdin);
    if (i == EOF)
    {
        /*free(line);*/
        return (NULL);
    }
    return (line);
}
/**
 * main - the main function of the shell
 * argc: argumment count
 * argv: argumment vector
 * Return: int 0
 */
int main(int argc, char **argv)
{
    char *line_read;
    char **cmd;

    cmd = NULL;
    line_read = NULL;
    while (1)
    {
        line_read = read_line();
        if (!line_read)
        {
            if (isatty(STDIN_FILENO))
            {
                write(1, "\n", 1);
            }
            return (0);
        }
    }
}

#include "simple_shell.h"
/**
 * promptt - put a $ in the stdin
 */
void promptt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 3);
	}
}

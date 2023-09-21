#include "simple_shell.h"
/**
 * promptt - put a $ in the stdin
 */
void	promptt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 3);
	}
}

/**
 * ft_strdup - duplicate string s1
 * @s1: string to duplicate
 * Return: ptr to dup string  null if fails
 */
char	*ft_strdup(const char	*s1)
{
	char	*rtn;
size_t	len;

	len = ft_strlen(s1) + 1;
	rtn = malloc(sizeof(char) * len);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, len);
	return (rtn);
}

/**
 * ft_memcpy - cpy n byte from mem src to dest
 * @dst: destination of cp
 * @src: to copy from
 * @n: size ofbytes to copy
 * Return: returns a pointer to dst or 0
 */
void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	char	*dstc;
	const char	*srccc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dstc = (char *)dst;
	srccc = (const char *)src;
	while (n--)
		dstc[n] = srccc[n];
	return (dst);
}

/**
 * ft_strlen -  count the length of a string
 * @str: line to count it s length
 * Return: length of str
 */
int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * free_args - free a double pointer char
 * @args: pointers to free
 */
void	free_args(char	**args)
{
	int	i;

	i = 0;
	if (args == NULL)
	{
		return;
	}
	for (i = 0; args[i]; i++)
	{
		free(args[i]), args[i] = NULL;
	}
	free(args);
	args = NULL;
}



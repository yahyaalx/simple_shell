#include "simple_shell.h"

/**
 * ft_strcmp - compare two strings
 * @s1: string to compare to
 * @s2: string to compare to
 * Return: an int less equal or greater than 0
 */
int	ft_strcmp(const char	*s1, const char	*s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

/**
 * ft_strcpy - copy a line from src to des
 * @dest: destination buffer
 * @src: source buffer to copy from
 * Return: pointer to dest
 */
char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

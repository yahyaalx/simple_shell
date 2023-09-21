#include "simple_shell.h"

/**
 * tokens - tokenise the line that have been read
 * @line: line to tokenise
 * Return: tokenized strings
 */
char	**tokens(char	*line)
{
	int	counter, i;
	char	*tempo, *tokenise;
	char **command;

	counter = 0;
	if (!line)
		return (NULL);
	tempo = ft_strdup(line);
	if (!tempo)
		return (NULL);
	tokenise = strtok(tempo, " \t\n\a\r");
	if (tokenise == NULL)
	{
		free(tempo);
		free(line);
		return (NULL);
	}
	while (tokenise)
	{
		counter++;
		tokenise = strtok(NULL, " \t\n\a\r");
	}
command = malloc(sizeof(char *) * (counter + 1));
	if (!command)
	{
		free(tempo);
		return (NULL);
	}
	ft_strcpy(tempo, line);
	tokenise = strtok(tempo, " \t\n\a\r");
	i = 0;
	while (tokenise)
	{
		command[i++] = ft_strdup(tokenise);
		tokenise = strtok(NULL, " \t\n\a\r");
	}
	command[i] = NULL;
	free(tempo);
	free(line);
	return (command);
}
/**
 * read_line - read line from stdin
 * Return: line read
 */
char	*read_line(void)
{
	char	*line;
	size_t	n;
	int	i;

	line = NULL;
	n = 0;
	promptt();
	i = getline(&line, &n, stdin);
	if (i == EOF)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/**
 * execution - execution of commands
 * @cmd: command to execute
 * @argv: argument vector
 * @env: environment variable
 * Return: exit status of i wait pid
 */
int	execution(char	**cmd, char	**argv, char	**env)
{
	int	i;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror(argv[0]);
			free_args(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &i, 0);
		free_args(cmd);
	}
	return (WEXITSTATUS(i));
}
/**
 * shell_loop - main loop for the shell
 * @argv: argument vector
 * @env: environment
 * Return: status of exit
 */
int	shell_loop(char	**argv, char	**env)
{
	char	*line_read;
	char	**cmd;
	int	status;

	cmd = NULL;
	line_read = NULL;
	status = 0;

	while (1)
	{
		line_read = read_line();
		if (line_read == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(1, "\n", 1);
			}
			return (status);
		}
		cmd = tokens(line_read);
		if (cmd == NULL)
		{
			continue;
		}
		status = execution(cmd, argv, env);
	}
}
/**
 * main - the main function of the shell
 * @argc: argumment count
 * @argv: argumment vector
 * @env: enviorenment variable
 * Return: always return 0
 */
int	main(int	argc, char	**argv, char	**env)
{
	int	exxxit;

	if (argc != 1)
	{
		write(2, "too many argumments\n", 20);
		exit(1);
	}

	exxxit = shell_loop(argv, env);
	return (exxxit);
}

#include "main.h"
/**
 *main - entry point
 *@ac: num of args
 *@av: array of args
 *@env: array of environment variable
 *
 * Description: controls the flow of program
 * Return: 0 when successful only
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	pid_t my_pid;
	char *buf_in;
	char **argv;
	int num_token, status;
	ssize_t gn;
	size_t n;
	struct stat st;

	while (1)
	{
		_print("($) ");
		gn = getline(&buf_in, &n, stdin);
		if (gn == -1)
			my_exit(argv, buf_in);
		/* allocate space for token pointers */
		num_token = get_tokens(buf_in);
		argv = alloc(num_token);
		/* tokenize */
		tokenize(argv, buf_in);
		/* check if argv[0] is exit */
		if (check_built(argv[0], env, argv, buf_in))
			continue;
		if (stat(argv[0], &st) != 0)
		{
			_print("%: 1: %: not found\n", av[0], argv[0]);
			continue;
		}
		/* create child process */
		my_pid = fork();
		if (my_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				perror("No: ");
		}
		else
			wait(&status);
	}
	return (0);
}



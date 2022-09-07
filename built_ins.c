#include "main.h"
/**
 *my_exit- terminates shell
 *@argv: array of tokens
 *@buf: getline buf
 *
 *Description: terminates shell
 */
void my_exit(char **argv, char *buf)
{
	free_space(argv, buf);
	exit(0);
}
/**
 *my_env - print environment variables
 *@environ: string array of environment variables
 *
 *Description: prints out all environment variables
 */
void my_env(char **environ)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		_print("%\n", environ[i]);
		i++;
	}
}
/**
 *check_built - check first argument
 *@avg: first argument
 *@env: string array
 *@argv: array of tokens
 * @buf: getline buffer
 *
 *Description: check if avg equals any of built in functions
 *Return: 1 if argv[0] is a built in
 */
int check_built(char *avg, char **env, char **argv, char *buf)
{
	if (_strcmp(avg, "exit"))
	{
		my_exit(argv, buf);
	}
	else if (_strcmp(avg, "env"))
	{
		my_env(env);
		_print("\n");
		return (1);
	}
	return (0);
}


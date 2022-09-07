#include "main.h"
/**
 *alloc- allocate space to array of pointers
 *@num_tokens: number of tokens to allocate for
 *
 *Description: allocates space for num_tokens tokens
 *Return: pointer to newly allocated space
 */
char **alloc(int num_tokens)
{
	char **argv;
	size_t size;

	size = sizeof(char *)  * num_tokens;
	argv = malloc(size);

	return (argv);
}
/**
 *get_tokens- return num of tokens
 *@str: line entered by user
 *
 *Description: counts num of seperate words in a string
 *Return: number of tokens
 */
int get_tokens(char *str)
{
	int num, i;

	i = 0;
	num = 2;
	while (*(str + i) != '\0')
	{
		if (str[i] == ' ')
			num++;
		i++;
	}
	return (num);
}
/**
 *tokenize - seperate str into tokens
 *@argv: array of pointers for tokens
 *@buf: string to split
 *
 * Description: seperates buf into tokens and store in argv
 * Return: array of pointers
 */
char **tokenize(char **argv, char *buf)
{
	int i;
	char *token;

	token = strtok(buf, " \n");
	i = 0;
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 *free_space - frees space
 *@buf: getline string
 *@argv: array of tokens
 *
 *Descritpion: free all spaces
 */
void free_space(char **argv, char *buf)
{
	int i;

	if (buf != NULL)
		free(buf);

	if (argv == NULL)
		return;

	i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i] != NULL)
			free(argv[i]);
		i++;
	}
	free(argv);
}



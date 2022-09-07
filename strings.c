#include "main.h"
/**
 *_strlen- count char in a string
 *@str: string to find length of
 *
 *Description: counts number of characters in a string
 *Return: number of chars
 */
int _strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}

	return (i);
}
/**
 *_strcpy - copies contents
 *@dest: string to copy into
 *@src: string to copy from
 *
 *Description: copies chars of src into dest
 *Return: dest pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (src == NULL)
		return (NULL);

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
/**
 *_print- print string to stdout
 *@str: string to output
 *
 *Description: writes to standard output
 *Return: number of chars written to stdout
 */
int _print(char *str, ...)
{
	int i, j, nb;
	int nw;
	char *buf, *s;
	va_list vl;

	va_start(vl, str);
	i = 0;
	nb = 0;
	buf = malloc(10024 * sizeof(char));
	if (str == NULL)
		return (-1);

	while (*(str + i) != '\0')
	{
		if (str[i] == '%')
		{
			s = va_arg(vl, char *);
			j = 0;

			while (s[j] != '\0')
			{
				buf[nb] = s[j];
				j++;
				nb++;
			}
			i++;
		}
		else
		{
			buf[nb] = str[i];
			i++;
			nb++;
		}
	}
	nw = write(STDOUT_FILENO, buf, nb);
	return (nw);
}
/**
 *_strcmp- compares two string
 *@s1: first string
 *@s2: second string
 *
 *Description: compares two string
 *Return: 1 if strings are identical, 0 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}


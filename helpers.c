#include "monty.h"

/**
 * _putchar - entry point
 * @c: character
 * Return: 0 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _fgetc - reads characters from stream
 * @fd: characters to read
 * Return: buffer or eof
 */

int _fgetc(int fd)
{
	static char buffer[BUFSIZ];
	static ssize_t buf_pos;
	static ssize_t buf_size;

	if (buf_pos >= buf_size)
	{
		buf_size = read(fd, buffer, BUFSIZ);
		buf_pos = 0;
		if (buf_size <= 0)
			return (EOF);
	}

	return (buffer[buf_pos++]);
}

/**
 * _strtok - splits an array of srings
 * @str: the splited array of strings
 * @delim: the delemiter signe
 * Return: spleted string on succses and NULL if there is no more tokens
 */

char *_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next_token;
	char *current_token;
	const char *d;
	static int prev_not_d;

	if (str != NULL)
	{
		token = str;
		prev_not_d = 0;   /* in case of new string but not first call*/
	}
	if (token == NULL || *token == '\0')
		return (NULL);
	current_token = token;
	while (*token != '\0')
	{
		d = delim;

		if (*token == *d)
		{
			if ((prev_not_d))
			{
				*token = '\0';
				next_token = token + 1;
				token = next_token;
				prev_not_d = 0;
				return (current_token);
			}
			else
				current_token++;
			prev_not_d = 0;
		}
		else
			prev_not_d = 1;
		token++;
	}
	if (prev_not_d)
		return (current_token);
	else
		return (NULL);
}

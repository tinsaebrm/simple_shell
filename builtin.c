#include "shell.h"

/**
 * check_interactive - checks if the shell is in interactive mode
 * @info: pointer to the info_t structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int check_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
		return (1);
		delim++;
	}
	return (0);
}

/**
 * is_alpha - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if the character is alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * string_to_integer - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the converted integer value, or 0 if no numbers in the string
 */
int string_to_integer(char *s)
{
	int i, sign = 1, flag = 0;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
		sign *= -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
		result = result * 10 + (s[i] - '0');
	}
	else if (flag == 1)
	{
		flag = 2;
	}
	}

	if (sign == -1)
	result = -result;

	return (result);
}
/*
 * Contributor: Akoh inmiogbegbile
 *
 * This code provides utility functions for string
 * manipulation and shell functionality:
 * - check_interactive: Checks if the shell is in interactive mode.
 * - is_delimiter: Checks if a character is a delimiter.
 * - is_alpha: Checks if a character is alphabetic.
 * - string_to_integer: Converts a string to an integer.
 */

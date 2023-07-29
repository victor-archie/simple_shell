#include "shell.h"

/**
 * num_to_string - converts a number to a string.
 * @number: number to be converten in an string.
 * @string: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void num_to_string(long num, char *str, int base)
{
	int idx = 0, inNegative = 0;
	long x = number;
	char alpha[] = {"0123456789abcdef"};

	if (x == 0)
		str[idx++] = '0';

	if (str[0] == '-')
		inNegative = 1;

	while (x)
	{
		if (x < 0)
			str[idx++] = alpha[-(x % base)];
		else
			str[idx++] = alpha[x % base];
		x /= base;
	}
	if (inNegative)
		str[idx++] = '-';

	str[idx] = '\0';
	_strrev(str);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origen.
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- analisys sign*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/*2 - extract the number */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - count the coincidences of character in string.
 *
 * @string: pointer to str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */
int count_characters(char *str, char *character)
{
	int i = 0, count = 0;

	for (; str[i]; i++)
	{
		if (str[i] == character[0])
			count++;
	}
	return (count);
}

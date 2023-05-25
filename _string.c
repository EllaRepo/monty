#include "monty.h"
/**
 * reverse - reverses a string
 * @str: string
 * @length: length of string
 *
 * Return: None
*/
void reverse(char str[], int length)
{
	int start = 0, end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
/**
 * itoa - integer to ascii converter
 * @num: integer
 * @str: string
 *
 * Return: string corresponding to the integer
*/
char *itoa(unsigned int num, char *str)
{
	int rem, i = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0)
	{
		rem = num % 10;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= 10;
	}
	str[i] = '\0';
	reverse(str, i);

	return (str);
}

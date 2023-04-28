#include "main.h"
#include <stddef.h>
/**
 * print_character - prints a single character
 * @lists: va_list containing the character to be printed
 * Return: number of character printed
 */
int print_char(va_list list)
{
	char ch = va_arg(list, int);
	putchar(ch);
	return (1);
}

/**
 * print_string - prints a null terminated string
 * @lists: va_list containing the string to be printed
 * Return: number of character printed
 */
int print_str(va_list list)
{
	char *str = va_arg(list, char *);
	int i;

	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i]; i++)
	{
		putchar(str[i]);
	}
	return (i);
	
}

/**
 * print_percent - print a percent symbol
 * @lists: unused
 * Return: the number of characters printed
 */
int print_mod(__attribute__((unused)) va_list list)
{
	putchar('%');
	return (1);
}

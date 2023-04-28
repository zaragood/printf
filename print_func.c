#include "main.h"
#include <stddef.h>
/**
 * print_char - prints a single character
 * @list: va_list containing the character to be printed
 * Return: number of character printed
 */
int print_char(va_list list)
{
	char ch = va_arg(list, int);

	putchar(ch);
	return (1);
}

/**
 * print_str - prints a null terminated string
 * @list: va_list containing the string to be printed
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
 * print_mod - print a percent symbol
 * @list: unused
 * Return: the number of characters printed
 */
int print_mod(__attribute__((unused)) va_list list)
{
	putchar('%');
	return (1);
}

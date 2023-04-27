#include "main.h"
#include <stddef.h>
/**
 * print_character - prints a single character
 * @lists: va_list containing the character to be printed
 * Return: number of character printed
 */
int print_character(va_list lists)
{
	char ch = va_arg(lists, int);
	putchar(ch);
	return (1);
}

/**
 * print_string - prints a null terminated string
 * @lists: va_list containing the string to be printed
 * Return: number of character printed
 */
int print_string(va_list lists)
{
	char *string = va_arg(lists, char *);
	int i;

	if (string == NULL)
	{
		string = "(null)";
	}
	for (i = 0; string[i]; i++)
	{
		putchar(string[i]);
	}
	return (i);
	
}

/**
 * print_percent - print a percent symbol
 * @lists: unused
 * Return: the number of characters printed
 */
int print_percent(__attribute__((unused)) va_list lists)
{
	putchar('%');
	return (1);
}

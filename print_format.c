#include "main.h"
#include <stddef.h>
/**
 * print_all - prints anything, with specific formats for different data types
 *
 * @format: a string of format specifiers for the data to be printed
 * @...: variable number of arguments that correspond to the format specifiers
 *
 * Return: the total number of characters printed
 *
 * Description: This function is a variadic function that can print any data type
 * based on a format string that specifies the type of each argument. The format
 * string uses format specifiers such as %d, %s, %c, and %f to indicate the type
 * of each argument. This function uses a struct to map each format specifier to
 * its corresponding print function, and iterates over the format string to print
 * each argument using the appropriate function. If an invalid format specifier is
 * encountered, the function simply skips it and continues printing the rest of the
 * arguments. The function returns the total number of characters printed.
 */
int _printf(const char *format, ...)
{
	/* Array of function pointers for each conversion specifier */

	va_list list;
	int len = 0, i = 0, j, array_len;
	prt format_funcs[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_mod},
	};

	/* check if format is valid*/
	if (format == NULL)
		return (-1);

	/* starts the printing process*/
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			len++;
		}
		else
		{
			i++;
			array_len = sizeof(format_funcs) / sizeof(format_funcs[0]);
			for (j = 0; j < array_len; j++)
			{
				if (format[i] == format_funcs[j].specifier)
				{
					len += format_funcs[j].print(list);
					break;
				}
			}
			if (format[i] != format_funcs[j].specifier)
			{
				i--;
				putchar(format[i]);
				len++;
			}
		}
		i++;
	}
	va_end(list);
	return (len);
}

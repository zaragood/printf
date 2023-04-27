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
	prt funcs[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	/*variadic list */
	va_list lists;

	/* pointer to type prt to store the address to the first element in the array */
	prt *func = NULL;
	int length = 0, i = 0;
	va_start(lists, format);

	/* loop through the format string until the end is reached */
	while (format[i])
	{
		/* check if character in the format string == % */
		if (format[i] != '%')
		{
			/* print the format string if not equal to  % */
			putchar(format[i]);
			length++;
		}
		else
		{
			i++;
			/* Initialize the function pointer to the first element of the func array*/
			func = funcs;

			/* Loop through the function pointer array until a NULL specifier is reached */
			while (func->specifier != '\0')
			{
				/* Check if the current format character matches the specifier
   for the current function pointer. If they match, call the
   print function to handle the conversion. */
				if (format[i] == func->specifier)
				{
					length += func->print(lists);
					break;
				}
				func++;
			}
			if (format[i] != func->specifier)
			{
				i--;
				putchar(format[i]);
				length++;
			}
			
		}
		i++;
	}
	va_end(lists);

	return (length);

}

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct check_format - struct to map format specifiers to their print functions
 *
 * @specifier: the format specifier character
 * @print: function pointer to the print function for the specifier
 *
 * Description: This struct is used to map format specifiers (such as %d or %s)
 * to their corresponding print functions. The @specifier field is a character
 * that represents the format specifier, and @print is a function pointer that
 * points to the corresponding print function for the format specifier.
 */

typedef struct check_format
{
	char specifier;
	int (*print)(va_list lists);
} prt;

int _printf(const char *format, ...);

int print_character(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
#endif /*MAIN_H*/

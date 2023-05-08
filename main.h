#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct print_format - struct to map format specifiers
 * to their print functions
 *
 * @specifier: the format specifier character
 * @print: function pointer to the print function for the specifier
 *
 * Description: This struct is used to map format specifiers (such as %d or %s)
 * to their corresponding print functions. The @specifier field is a character
 * that represents the format specifier, and @print is a function pointer that
 * points to the corresponding print function for the format specifier.
 */
typedef struct print_format
{
	char specifier;
	int (*print)(va_list list);
} prt;

int print_char(va_list list);
int print_str(va_list list);
int print_mod(va_list list);
int _printf(const char *format, ...);
int print_int(va_list list);
int int_helper(unsigned int value);
int print_binary(va_list list);
int binary_helper(int value);
#endif /* MAIN.H */

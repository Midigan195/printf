#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include"main.h"
/**
 * print_char - Prints specified character to command terminal
 * @c: character to be printed
*/

void print_char(char c)
{
        write(1, &c, 1);
}

/**
 * print_string - prints a string to the console
 * @s: pointer to string
*/

int print_string(char *s)
{
        int i = 0;

        while (s[i] != '\0')
        {
                print_char(s[i]);
                i++;
        }
	return(i);
}

/**
 * _printf - Prints string and variadic arguments to terminal
 * @format: pointer to string
 * Return: 0 if sucessful
*/

int _printf(const char *format, ...)
{
	va_list ptr;
	char *p = NULL;
	int i = 0;
	int count = 0;
	int found = 1;
	
	p = malloc(sizeof(char));
	*p = '%';
	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					count++;
					print_char(va_arg(ptr, int));
					i += 2;
					found = 0;
					break;
				case 's':
					count += print_string(va_arg(ptr, char *));
					i += 2;
					found = 0;
					break;
				case '%':
					i += 2;
					print_char(*p);
					free(p);
					count++;
					found = 0;
					break;
				case 'd':
					i += 2;
					count += print_num(va_arg(ptr, int));
					found = 0;
					break;
				case 'i':
					i += 2;
					count += print_num(va_arg(ptr, int));
					found = 0;
					break;
				default:
					break;
			}
			if (found == 0)
				continue;
		}
		print_char(format[i]);
		i++;
		count++;
	}
	va_end(ptr);
	return (count);
}

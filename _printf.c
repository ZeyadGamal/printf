#include "main.h"

void print_buffer(char buffer[], int *buff_i);

/**
 * _printf - function that prints to console
 * @format: format
 * @...: data to be printed
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int i;
	int printed = 0;
	int printed_chars = 0;
	int flags, precision, buff_i, size, width = 0;
	va_list list;
	char buffer[1024];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_i++] = format[i];
			if (buff_i == 1024)
				print_buffer(buffer, &buff_i);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_i);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			i++;
			printed = print_handler(format, &i, list, buffer, flags,
						 width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_i);
	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - printed the contents of the buffer
 * @buffer: buffer
 * @buff_i: index of buffer
 */
void print_buffer(char buffer[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buffer[0], *buff_i);
	*buff_i = 0;
}

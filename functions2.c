#include "main.h"
#include <stdio.h>
#include <math.h>

/**
 * print_unsigned - Prints an unsignd number integer
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precis specs
 * @size: Size spec
 * Return: Number of chars printed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 1024 - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*
 * print_octal - Prints an octal number integer
 * @types: arguments as always
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precisi spec
 * @size: Size spec
 * Return: Number of chars
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = 1024 - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[1024 - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & 8 && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints a hexadecimal number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flag
 * @width: get width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of chars printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an upper hexadecimal number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precision specs
 * @size: Size spec
 * Return: Number of chars printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints  hexadecimal number
 * @types: arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer
 * @flags: active flags
 * @flag_ch: active flags
 * @width: get width
 * @precision: Precison specs
 * @size: Size specification
 * Return: Number of chars printed.
 */


int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


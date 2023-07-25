#include "main.h"

/**
 * print_char - print character according to params
 * @types: arguments
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision specification according to params
 * @size: size spec
 * Return: number of chars
 */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - prints a string
 * @types: arguments
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision specification
 * @size: size specification
 * Return: number of chars
 */
int print_string(va_list types, char buffer[], int flags,
			int width, int precision, int size)
{
	int l = 0;
	int i;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
	{
		s = "(null)";
		if (precision > 5)
			s = "      ";
	}
	while (s[l] != '\0')
		l++;

	if (precision >= 0 && precision < l)
		l = precision;

	if (width > l)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], l);
			for (i = width - l; i > 0; i--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (i = width - l; i > 0; i--)
				write(1, "", 1);
			write(1, &s[0], l);
			return (width);
		}
	}
	return (write(1, s, l));
}
/**
 * print_percent - prints a percenage of number
 * @types: argument specs
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - prints an integer according to params
 * @types: arguments
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision specs
 * @size: size specs
 * Return: number of characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - prints a binary number
 * @types: arguments
 * @buffer: buffer array
 * @flags: active flags
 * @width: width
 * @precision: precision specs
 * @size: size spec
 * Return: number of characters
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

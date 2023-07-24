#include <stdio.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_unsigned - Prints an unsigned number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
                   int flags, int width, int precision, int size)
{
    const int buf_size = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = convert_size_unsgnd(num, size);

}

/**
 * print_octal - Prints an octal number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed.
 */
int print_octal(va_list types, char buffer[],
                int flags, int width, int precision, int size)
{
    const int buf_size = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    num = convert_size_unsgnd(num, size);

}

/**
 * print_hexadecimal - Prints a hexadecimal number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed.
 */
int print_hexadecimal(va_list types, char buffer[],
                      int flags, int width, int precision, int size)

/**
 * print_hexa_upper - Prints an upper hexadecimal number
 * @types: arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed.
 */
int print_hexa_upper(va_list types, char buffer[],
                      int flags, int width, int precision, int size)

/**
 * print_hexa - Prints a hexadecimal number
 * @types: arguments
 * @map_to: map the number to
 * @buffer: Buffer
 * @flags: active flags
 * @flag_ch: active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specification
 * Return: Number of chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
               int flags, char flag_ch, int width, int precision, int size)


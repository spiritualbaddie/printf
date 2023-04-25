#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * convert_fmt_r - Prints the reversed string
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void convert_fmt_r(va_list *args_list, fmt_info_t *fmt_info)
{
	int i, len;
	char *str = va_arg(*args_list, char *);

	if (str)
	{
		len = str_len(str);
		if (!fmt_info->left)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->pad);
		}
		for (i = len - 1; i >= 0; i--)
		{
			_putchar(*(str + i));
		}
		if (fmt_info->left)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->pad);
		}
	}
}

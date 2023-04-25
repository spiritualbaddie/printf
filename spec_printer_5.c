#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * convert_fmt_S - Prints a string and the hex code for
 * \ non-printable characters
 * @args_list: The arguments list
 * @fmt_info: The format info
 *
 * Return: The number of characters written
 */
void convert_fmt_S(va_list *args_list, fmt_info_t *fmt_info)
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
		for (i = 0; *(str + i) != '\0'; i++)
		{
			if (*(str + i) < 32 || *(str + i) >= 127)
			{
				_putchar('\\');
				_putchar('x');
				_putchar(TO_UPPER(hex_digit(*(str + i) / 16)));
				_putchar(TO_UPPER(hex_digit(*(str + i) % 16)));
			}
			else
			{
				_putchar(*(str + i));
			}
		}
		if (fmt_info->left)
		{
			for (i = 0; i < MAX(len, fmt_info->width) - len; i++)
				_putchar(fmt_info->pad);
		}
	}
	else
	{
		_putstr("(null)");
	}
}

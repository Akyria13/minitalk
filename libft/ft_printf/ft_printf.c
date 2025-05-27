/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:33:47 by jowagner          #+#    #+#             */
/*   Updated: 2025/01/20 17:33:44 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_args(va_list args, char c)
{
	if (args == NULL)
		return (-1);
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'i' || c == 'd')
		return (ft_print_itoa(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_base(va_arg(args, int), c));
	return (0);
}

/**
 * @brief A custom implementation of the printf() function.
 * This function mimics the original printf() from libc,
 * handling formatted output to the standard output stream.
 *
 * @param format The format string containing text and format specifiers.
 * @param ... Additional arguments to format and print based on the format
 * specifiers.
 *
 * @return The number of characters printed
 * (excluding the null byte used to end output to strings),
 * or a negative value if an error occurs.
 */
int	ft_printf(const char *format, ...)
{
	int		count;
	char	c;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		c = *(format + 1);
		if (*format == '%' && *(format + 1))
		{
			count += ft_check_args(args, c);
			format++;
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

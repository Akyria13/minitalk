/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:30:54 by jowagner          #+#    #+#             */
/*   Updated: 2025/01/20 17:33:34 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long n)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr(n / 16);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	else
	{
		count = 0;
		count += ft_putstr("0x");
		count += ft_putptr(ptr);
	}
	return (count);
}

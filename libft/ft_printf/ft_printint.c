/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:00:58 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/07 18:55:18 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an integer to a string representation.
 *
 * @param n The integer to convert.
 * @return A pointer to the newly allocated string representing the integer,
 * or NULL if memory allocation fails.
 */
char	*ft_itoa_printf(int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	len = ft_numlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (n < 0)
		str[0] = '-';
	while (len > 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		if (n < 0 && len == 0)
			str[len] = '-';
	}
	return (str);
}

int	ft_print_itoa(int nbr)
{
	int		count;
	int		i;
	char	*str;

	count = 0;
	i = 0;
	str = ft_itoa_printf(nbr);
	if (!str)
		return (0);
	while (str && str[i])
		count += ft_putchar(str[i++]);
	free(str);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	c = (n % 10 + '0');
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_base(unsigned int n, char c)
{
	int			count;
	const char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_putnbr_base(n / 16, c);
	count += write(1, &base[n % 16], 1);
	return (count);
}

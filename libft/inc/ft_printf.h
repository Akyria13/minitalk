/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:11:01 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/24 18:48:27 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_print_itoa(int nbr);
int	ft_printf(const char *format, ...);
int	ft_print_ptr(unsigned long ptr);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_base(unsigned int n, char c);

#endif

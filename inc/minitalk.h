/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:29:33 by jolanwagner       #+#    #+#             */
/*   Updated: 2025/05/27 14:48:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

typedef struct s_message
{
	unsigned char	current_char;
	int				bit_position;
}					t_message;

volatile sig_atomic_t	g_signal_received = 1;

#endif

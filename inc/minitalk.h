/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolanwagner13 <jolanwagner13@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:29:33 by jolanwagner       #+#    #+#             */
/*   Updated: 2025/06/02 16:34:59 by jolanwagner      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

volatile sig_atomic_t	g_signal_received = 1;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:54:00 by jolanwagner       #+#    #+#             */
/*   Updated: 2025/05/27 14:47:52 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_position = 0;

	(void)context;
	g_signal_received = 0;
	if (signum == SIGUSR2)
		current_char |= (1 << (7 - bit_position));
	bit_position++;
	if (bit_position == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_char = 0;
		bit_position = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction	sa;
	pid_t 				pid;

	pid = getpid();
	ft_printf("\n\033[1;93mServer PID :\033[0m %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		while (g_signal_received != 0)
			pause();
		g_signal_received = 1;
	}
	return (0);
}

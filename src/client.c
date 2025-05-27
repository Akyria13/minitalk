/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:54:23 by jolanwagner       #+#    #+#             */
/*   Updated: 2025/05/27 14:47:55 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	(void)signum;
	g_signal_received = 0;
}

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_signal_received != 0)
			pause();
		g_signal_received = 1;
		i--;
	}
}

void	send_message(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char(server_pid, str[i++]);
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	if (argc != 3)
		return (ft_printf("Usage : %s <PID> <message>\n", argv[0]), 1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (ft_printf("PID incorrect.\n"), 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, argv[2]);
	return (0);
}

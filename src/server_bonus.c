/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:54:00 by jolanwagner       #+#    #+#             */
/*   Updated: 2025/05/28 20:40:25 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_reset(char **message, int *len, siginfo_t *info)
{
	if (*message)
	{
		ft_printf("%s\n", *message);
		free(*message);
	}
	*message = NULL;
	*len = 0;
	kill(info->si_pid, SIGUSR2);
}

static char	*add_char(char *old, char c, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(len + 2);
	if (!new)
		return (old);
	while (i < len && old)
	{
		new[i] = old[i];
		i++;
	}
	new[len] = c;
	new[len + 1] = '\0';
	if (old)
		free(old);
	return (new);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_position = 0;
	static char				*message = NULL;
	static int				len = 0;

	(void)context;
	g_signal_received = 0;
	if (signum == SIGUSR2)
		current_char |= (1 << (7 - bit_position));
	bit_position++;
	if (bit_position == 8)
	{
		if (current_char == '\0')
			print_reset(&message, &len, info);
		else
		{
			message = add_char(message, current_char, len);
			if (message)
				len++;
		}
		current_char = 0;
		bit_position = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

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

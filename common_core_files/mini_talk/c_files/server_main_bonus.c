/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:57:57 by halragga          #+#    #+#             */
/*   Updated: 2026/02/05 02:44:39 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk_bonus.h"

static void	ft_exit(int code, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 1);
	exit(code);
}

static void	ft_str_saver(char new_c, pid_t client_pid)
{
	static char	buffer[1024 * 1024];
	static int	i;

	if (new_c == '\0')
	{
		buffer[i] = new_c;
		ft_putstr_fd(buffer, 1);
		write(1, "\n", 1);
		i = 0;
		kill(client_pid, SIGUSR2);
	}
	else
	{
		if (i < ((int) sizeof(buffer)) - 1)
			buffer[i++] = new_c;
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit_index;
	static char		crnt_char;

	(void)context;
	crnt_char <<= 1;
	if (signum == SIGUSR2)
		crnt_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_str_saver(crnt_char, info->si_pid);
		bit_index = 0;
		crnt_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit(1, "Error: sigaction failed!\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit(2, "Error: sigaction failed!\n");
	while (1)
		pause();
	return (0);
}

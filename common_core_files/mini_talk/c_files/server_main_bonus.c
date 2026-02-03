/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:57:57 by halragga          #+#    #+#             */
/*   Updated: 2026/02/03 11:49:28 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

static void	server_error(void)
{
	write(2, "Server Error!\n", 13);
	exit(3);
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int		bit_index;
	static char		crnt_char;
	static pid_t	c_pid;

	(void)context;
	if (c_pid == 0)
		c_pid = info->si_pid;
	crnt_char <<= 1;
	if (signum == SIGUSR2)
		crnt_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &crnt_char, 1);
		bit_index = 0;
		crnt_char = 0;
	}
}
/*
	val = kill(info->si_pid, SIGUSR2);
	if (val == -1)
		server_error();
*/

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: sigaction failed!\n", 1);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: sigaction failed!\n", 1);
		exit(2);
	}
	while (1)
		pause();
}

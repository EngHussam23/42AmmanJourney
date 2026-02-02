/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:57:57 by halragga          #+#    #+#             */
/*   Updated: 2026/02/02 19:07:08 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit_index;
	static char	crnt_char;

	(void)info;
	(void)context;
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

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(2);
	while (1)
		pause();
}

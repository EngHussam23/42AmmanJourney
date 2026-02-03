/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:57:57 by halragga          #+#    #+#             */
/*   Updated: 2026/02/03 13:21:17 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

static void	ft_str_saver(char new_c)
{
	static char	buffer[1024 * 1024];
	static int	i;

	if (new_c == '\0')
	{
		buffer[i] = new_c;
		ft_putstr_fd(buffer, 1);
		write(1, "\n", 1);
		i = 0;
		
	}
	else
	{
		if (i < (int)sizeof(buffer) - 1)
			buffer[i++] = new_c;
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bit_index;
	static unsigned char	crnt_char;

	(void)info;
	(void)context;
	crnt_char <<= 1;
	if (signum == SIGUSR2)
		crnt_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_str_saver(crnt_char);
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
	return (0);
}

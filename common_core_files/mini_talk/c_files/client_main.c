/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:43:36 by halragga          #+#    #+#             */
/*   Updated: 2026/02/06 17:35:05 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	ft_exit(int code, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 1);
	exit(code);
}

// SIGUSR1 = 0
// SIGUSR2 = 1
static void	ft_send(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_exit(3, "Error: invalid kill call\n");
		}
		else if (kill(pid, SIGUSR1) == -1)
			ft_exit(3, "Error: invalid kill call");
		while (g_ack_received == 0)
			pause();
		bit--;
	}
}

static void	handle_ack(int signum)
{
	if (signum == SIGUSR1)
		g_ack_received = 1;
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	sb;

	sigemptyset(&sb.sa_mask);
	sb.sa_handler = handle_ack;
	sigaction(SIGUSR1, &sb, NULL);
	if (argc != 3)
		ft_exit(1, "Error: bad input!\nUsage: ./client <PID> <MSG>\n");
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		ft_exit(2, "Error: invalid PID\n");
	i = 0;
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	ft_send(pid, '\0');
	return (0);
}

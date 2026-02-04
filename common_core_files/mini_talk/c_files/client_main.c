/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:43:36 by halragga          #+#    #+#             */
/*   Updated: 2026/02/04 21:24:33 by halragga         ###   ########.fr       */
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

static void	ft_send(pid_t pid, char c)
{
	int	bit;
	int	timeout;

	bit = 7;
	timeout = 0;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_ack_received == 0)
			pause();
		bit--;
	}
}

static void	handle_ack(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		g_ack_received = 1;
	else if (signum == SIGUSR2)
		ft_exit(0, NULL);
}


int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*str;
	int					i;
	struct sigaction	sb;

	sigemptyset(&sb.sa_mask);
	sb.sa_sigaction = handle_ack;
	sb.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sb, NULL);
	sigaction(SIGUSR2, &sb, NULL);
	if (argc != 3)
		ft_exit(1, "Error: bad input!\nUsage: ./client <PID> <MSG>\n");
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		ft_exit(1, "Error: invalid PID\n");
	i = 0;
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	ft_send(pid, '\0');
	while (1)
		pause();
	return (0);
}

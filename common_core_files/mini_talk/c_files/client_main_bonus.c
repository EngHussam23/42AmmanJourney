/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:43:36 by halragga          #+#    #+#             */
/*   Updated: 2026/02/07 11:22:51 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk_bonus.h"

static volatile sig_atomic_t	g_ack_received = 0;

// error handling and exiting function with fd protection
// (to preven the fd = 0, the std input)
static void	ft_exit(int code, int fd, char *msg)
{
	if (msg && (fd == 1 || fd == 2))
		ft_putstr_fd(msg, 1);
	exit(code);
}

static void	ft_send(pid_t pid, char c)
{
	int	bit;

	bit = 7;
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
	static int	bit_received = 0;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		g_ack_received = 1;
		bit_received++;
		if (bit_received % 8 == 0)
			ft_putstr_fd("8 bits acknowledged\n", 1);
	}
	else if (signum == SIGUSR2)
		ft_exit(0, 1, "\n##message received!##\n");
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	sb;

	if (argc != 3)
		ft_exit(1, 2, "Error: bad input!\nUsage: ./client <PID> <MSG>\n");
	sigemptyset(&sb.sa_mask);
	sb.sa_sigaction = handle_ack;
	sb.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sb, NULL);
	sigaction(SIGUSR1, &sb, NULL);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		ft_exit(2, 2, "Error: invalid PID\n");
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

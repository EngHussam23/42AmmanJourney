/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:43:36 by halragga          #+#    #+#             */
/*   Updated: 2026/02/07 18:54:00 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk_bonus.h"

// static: file scope only.
/*
 * volatile: it alerts or tells the compiler to check the value all the time;
 * cuz it may change. (compiler optimization prevention)
 *
 * sig_atomic_t: keeps the operation in one CPU instruction and prevent
 * inturruptions.
 * safe to use in signal handlers.
 * coordinates timing between the main program and the signal handler
*/
static volatile sig_atomic_t	g_ack_received = 0;

// error handling and exiting function with fd protection
// (to preven the fd = 0, the std input)
static void	ft_exit(int code, int fd, char *msg)
{
	if (msg && (fd == 1 || fd == 2))
		write(fd, &msg, ft_strlen(msg));
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
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_exit(3, 2, "Error: invalid kill call\n");
		}
		else if (kill(pid, SIGUSR1) == -1)
			ft_exit(4, 2, "Error: invalid kill call\n");
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
			write(1, ".\n", 2);
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
	if (sigemptyset(&sb.sa_mask) == -1)
		ft_exit(2, 2, "Error:\nsigemptyset: invalid argument\n");
	sb.sa_sigaction = handle_ack;
	sb.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sb, NULL))
		ft_exit(5, 2, "Error: failed to setup sig handler\n");
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
		ft_exit(7, 2, "Error: invalid PID\n");
	if (kill(pid, 0) == -1)
		ft_exit(8, 2, "Error: invalid kill call\n");
	i = 0;
	while (argv[2][i])
		ft_send(pid, argv[2][i++]);
	ft_send(pid, '\0');
	while (1)
		pause();
	return (0);
}

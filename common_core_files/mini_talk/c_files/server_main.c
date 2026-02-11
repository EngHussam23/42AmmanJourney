/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:57:57 by halragga          #+#    #+#             */
/*   Updated: 2026/02/10 18:27:08 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	ft_exit(int code, int fd, char *msg, char **to_free);

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bit_index;
	static unsigned char	crnt_char;
	t_alloc					*alloc;

	(void)context;
	usleep(100);
	alloc = get_alloc_ptr(0);
	alloc->pid = info->si_pid;
	if (!(alloc->msg_str))
		alloc->msg_str = ft_strdup("");
	if (bit_index == 0)
		crnt_char = 0;
	crnt_char <<= 1;
	if (signum == SIGUSR2)
		crnt_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_str_saver(crnt_char, alloc);
		bit_index = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_exit(6, 2, "Error: signal sending failure\n", &alloc->msg_str);
}

static void	handle_sigint(int signum)
{
	(void)signum;
	get_alloc_ptr(1);
	write(1, "\nServer stopped.\n", 17);
	exit(0);
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sa_int;

	if (sigemptyset(&sa.sa_mask) == -1)
		ft_exit(1, 2, "Error:\nsigemptyset: invalid argument\n", NULL);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigemptyset(&sa_int.sa_mask) == -1)
		ft_exit(1, 2, "Error:\nsigemptyset: invalid argument\n", NULL);
	sa_int.sa_handler = handle_sigint;
	sa_int.sa_flags = 0;
	if (sigaction(SIGINT, &sa_int, NULL) == -1)
		ft_exit(6, 2, "Error: sigaction failed!\n", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit(7, 2, "Error: sigaction failed!\n", NULL);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit(8, 2, "Error: sigaction failed!\n", NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

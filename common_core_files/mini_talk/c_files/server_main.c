/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:57:57 by halragga          #+#    #+#             */
/*   Updated: 2026/02/08 07:32:02 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

// error handling and an pexiting function with fd protection
// (to preven the fd = 0, the std input)
static void	ft_exit(int code, int fd, char *msg)
{
	if (msg && (fd == 1 || fd == 2))
		write(fd, msg, ft_strlen(msg));
	exit(code);
}

static void	ft_str_saver(char new_c, char **msg_str)
{
	char	temp[2];
	char	*new_str;

	if (new_c == '\0')
	{
		write(1, *msg_str, ft_strlen(*msg_str));
		write(1, "\n", 1);
		free(*msg_str);
		*msg_str = ft_strdup("");
		if (!*msg_str)
			ft_exit(4, 2, "Error: failed to reset the message");
	}
	else
	{
		temp[0] = new_c;
		temp[1] = '\0';
		new_str = ft_strjoin(*msg_str, temp);
		if (!new_str)
			ft_exit(5, 2, "Error: failed to build the message\n");
		free(*msg_str);
		*msg_str = new_str;
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bit_index;
	static unsigned char	crnt_char;
	static char				*msg_str = NULL;

	(void)context;
	if (!msg_str)
		msg_str = ft_strdup("");
	crnt_char <<= 1;
	if (signum == SIGUSR2)
		crnt_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		ft_str_saver(crnt_char, &msg_str);
		bit_index = 0;
		crnt_char = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_exit(6, 2, "Error: signal sending failure\n");
}

int	main(void)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) == -1)
		ft_exit(1, 2, "Error:\nsigemptyset: invalid argument\n");
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		ft_exit(2, 2, "Error:\nsiggaddset: invalid argument\n");
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		ft_exit(3, 2, "Error:\nsiggaddset: invalid argument\n");
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_exit(7, 2, "Error: sigaction failed!\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit(8, 2, "Error: sigaction failed!\n");
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main _bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:43:36 by halragga          #+#    #+#             */
/*   Updated: 2026/02/04 17:28:48 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk_bonus.h"

static void	ft_send(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		sleep(1);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int		i;

	if (argc != 3)
	{
		ft_putstr_fd("Error: bad input!\nUsage: ./client <PID> <MSG>\n", 1);
		return (1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: invalid PID\n", 1);
		return (2);
	}
	str = argv[2];
	i = 0;
	while (str[i])
	{
		ft_send(pid, str[i]);
		i++;
	}
	ft_send(pid, '\0');
	return (0);
}

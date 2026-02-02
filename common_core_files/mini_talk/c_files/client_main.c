/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:43:36 by halragga          #+#    #+#             */
/*   Updated: 2026/02/02 19:18:32 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

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
		return (1);
	pid = (pid_t)ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		ft_send(pid, str[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:30:00 by halragga          #+#    #+#             */
/*   Updated: 2026/02/10 18:23:39 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	ft_exit(int code, int fd, char *msg, char **to_free)
{
	if (to_free && *to_free)
		free(*to_free);
	if (msg && (fd == 1 || fd == 2))
	{
		write(fd, msg, ft_strlen(msg));
		write(fd, "\n", 1);
	}
	exit(code);
}

void	ft_str_saver(char new_c, t_alloc *alloc)
{
	char	temp[2];

	if (new_c == '\0')
	{
		write(1, alloc->msg_str, ft_strlen(alloc->msg_str));
		write(1, "\n", 1);
		free(alloc->msg_str);
		alloc->msg_str = ft_strdup("");
		if (!(alloc->msg_str))
			ft_exit(4, 2, "Error: failed to reset the message", NULL);
	}
	else
	{
		temp[0] = new_c;
		temp[1] = '\0';
		alloc->temp = ft_strjoin(alloc->msg_str, temp);
		if (!(alloc->temp))
			ft_exit(5, 2, "Error: failed to build the message\n",
				&alloc->msg_str);
		free(alloc->msg_str);
		alloc->msg_str = alloc->temp;
		alloc->temp = NULL;
	}
}

t_alloc	*get_alloc_ptr(int clean)
{
	static t_alloc	alloc = {0};

	if (clean)
	{
		if (alloc.msg_str)
			free(alloc.msg_str);
		if (alloc.temp)
			free(alloc.temp);
		alloc.msg_str = NULL;
		alloc.temp = NULL;
		if (alloc.pid)
			kill(alloc.pid, SIGUSR2);
	}
	return (&alloc);
}

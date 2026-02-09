/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:30:00 by halragga          #+#    #+#             */
/*   Updated: 2026/02/09 16:29:17 by halragga         ###   ########.fr       */
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

void	ft_str_saver(char new_c, char **msg_str)
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
			ft_exit(4, 2, "Error: failed to reset the message", NULL);
	}
	else
	{
		temp[0] = new_c;
		temp[1] = '\0';
		new_str = ft_strjoin(*msg_str, temp);
		if (!new_str)
			ft_exit(5, 2, "Error: failed to build the message\n", msg_str);
		free(*msg_str);
		*msg_str = new_str;
	}
}

char	**get_msg_str_ptr(void)
{
	static char	*msg_str = NULL;

	return (&msg_str);
}

void	cleanup_msg_str(void)
{
	char	**msg_str_ptr;

	msg_str_ptr = get_msg_str_ptr();
	if (*msg_str_ptr)
	{
		free(*msg_str_ptr);
		*msg_str_ptr = NULL;
	}
}

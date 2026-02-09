/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:58:22 by halragga          #+#    #+#             */
/*   Updated: 2026/02/09 16:38:51 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

// required to enable usleep()
# define _DEFAULT_SOURCE

# define _XOPEN_SOURCE 700

// Standard libraries (allowed functions)
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

// My headers:
# include "libft.h"

// Utils functions (server only - not for client)
void	ft_str_saver(char new_c, char **msg_str);
char	**get_msg_str_ptr(void);
void	cleanup_msg_str(void);

#endif

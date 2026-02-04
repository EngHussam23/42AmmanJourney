/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:58:22 by halragga          #+#    #+#             */
/*   Updated: 2026/02/04 20:22:45 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_BONUS_H
# define MINI_TALK_BONUS_H

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

void	ft_exit(int code, char *msg);

#endif

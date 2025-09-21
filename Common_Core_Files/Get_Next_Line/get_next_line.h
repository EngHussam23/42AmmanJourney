/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:11:39 by halragga          #+#    #+#             */
/*   Updated: 2025/09/22 00:27:01 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#  ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
#  endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif

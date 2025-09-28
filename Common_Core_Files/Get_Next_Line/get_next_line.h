/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:11:39 by halragga          #+#    #+#             */
/*   Updated: 2025/09/28 20:45:29 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	get_len(const char *s);
char	*find_new_line(const char *s);
char	*join(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*str_duplicate(const char *src);
// void	*cpy(void *dest, const void *src, size_t cpysize);

#endif

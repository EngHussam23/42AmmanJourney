/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:30:34 by halragga          #+#    #+#             */
/*   Updated: 2025/08/09 17:41:33 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <bsd/string.h>
# include <string.h>
# include <ctype.h>

int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isdigit(int d);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		ft_bzero(void *ptr, size_t size);
void		*ft_memset(void *ptr, int fill, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t cpysize);
void		*ft_memmove(void *dest, const void *src, size_t mvsize0);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
//Update the prototypes bellow.
int			ft_atoi(void);
int			ft_strnstr(void);
int			ft_strncmp(void);
int			ft_strdub(void);
int			ft_memcmp(void);
int			ft_memchr(void);
int			ft_malloc(void);
int			ft_calloc(void);

#endif

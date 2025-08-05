/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:30:34 by halragga          #+#    #+#             */
/*   Updated: 2025/08/05 20:02:31 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>

void		ft_bzero(void *ptr, size_t size);
size_t		ft_strlen(const char *s);
int			ft_isalnum(int c);
int			ft_isprint(int c);
void		*ft_memset(void *ptr, int fill, size_t size);
int			ft_isdigit(int d);
int			ft_isascii(int c);
int			ft_isalpha(int c);

#endif

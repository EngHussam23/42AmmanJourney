/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:30:34 by halragga          #+#    #+#             */
/*   Updated: 2025/09/22 14:29:18 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isdigit(int d);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
//
int		ft_printf(const char *str, ...);
int		ft_print_void_ptr(void *ptr, int fd);
int		ft_print_hex(char str_fmt, unsigned int x, int count, int fd);
int		ft_print_unsigned_int(unsigned int n, int fd);
int		ft_write_char(char c, int fd, int count);
int		ft_write_str(char *str, int fd, int count);
int		ft_write_nbr(int n, int fd, int count);
//
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(char const *ptr);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *small, size_t length);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_bzero(void *ptr, size_t size);
void	*ft_memset(void *ptr, int fill, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t cpysize);
void	*ft_memmove(void *dest, const void *src, size_t mvsize0);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif

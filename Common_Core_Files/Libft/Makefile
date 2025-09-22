# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 20:17:30 by halragga          #+#    #+#              #
#    Updated: 2025/09/22 14:23:36 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The library file name
NAME = libft.a

# Compilation cmmand and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#Source files (.c)
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_print_void_ptr.c ft_print_hex.c ft_print_unsigned_int.c ft_write_char.c ft_write_str.c ft_write_nbr.c

# from .c to .o
# The object files (.o) will be created from the source files
OBJ = $(SRC:.c=.o)

all: $(NAME)

# Archive the object files into a static library
# The static library will be named libft.a
# $(OBJ) can be replaced by $(SRC:.c=.o)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all

# This rule makes sure that the targets: {all clean fclean re} are always executed
.PHONY: all clean fclean re
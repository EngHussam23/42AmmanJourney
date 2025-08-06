# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 20:17:30 by halragga          #+#    #+#              #
#    Updated: 2025/08/06 10:26:09 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#The library file name
NAME = libft.a

#Compilation cmmand and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#Source files (.c)
SRC = ft_atoi.c bzero.c ft_calloc.c ft_isallnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_malloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean: $(RM) $(OBJ) $(NAME)
fclean: clean
	$(RM) $(NAME)

re: fclean all

# .PHONY: all clean fclean re
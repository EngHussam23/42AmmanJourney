# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 20:17:30 by halragga          #+#    #+#              #
#    Updated: 2025/09/06 19:33:27 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The library file name
NAME = libft_printf.a

# Compilation cmmand and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -IHeader_files

RM = rm -f

#Source files (.c)
SRC_DIR = C_files
SRC = $(SRC_DIR)/test.c

# from .c to .o
OBJ_DIR = Object_files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# The object files (.o) will be created from the source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

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
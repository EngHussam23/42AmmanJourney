# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 13:10:47 by halragga          #+#    #+#              #
#    Updated: 2025/11/29 17:00:49 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The library file name
NAME = fractol

# Compilation command and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -lmlx -lXext -lX11 -lm

# Remove command
RM = rm -f

#Libft library
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

# Source files directory
SRC_DIR = C

# Source files (.c)
SRC = $(SRC_DIR)/ft_filename.c

# Object files directory
OBJ_DIR = Objects

# Create the object files directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Object files
# from .c to .o
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# The object files (.o) will be created from the source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target to run / build the project
all: $(NAME)

# Make the Libft library
$(LIBFT):
	make -C $(LIBFT_PATH)

# Build MLX
$(LIBFT):
	make -C $(LIBFT_PATH)

# Create the final executable by linking object files and Libft
$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) Libfttemp.a
	ar x Libfttemp.a
	ar rcs $(NAME) $(OBJ) *.o
	rm -f Libfttemp.a *.o

# clean the objects files
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean

# fclean the executables, archives, and object files
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# force clean then compile all over again
re: fclean all

# This rule makes sure that the targets: {all clean fclean re} are always executed
.PHONY: all clean fclean re
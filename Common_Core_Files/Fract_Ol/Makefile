# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 13:10:47 by halragga          #+#    #+#              #
#    Updated: 2025/11/30 13:47:31 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The executable file name:
NAME = fractol

# Compilation command:
CC = cc

# Compilation flags:
# -lmlx: MiniLibX library linking command; graphics lib, needed to open windows, draw pixels, create images, etc.
# -lX11: a library MiniLibX needs it to communicate with the display server.
# -lXext: X11 Extension library linking command; provides additional functionality for the X11 library, like image handling.
# -lm: Math library.
# -lz : Compression library.
MLX_FLAGS = -lmlx -lXext -lX11 -lm -lz
CFLAGS = -Wall -Wextra -Werror $(MLX_FLAGS)

# Remove command
RM = rm -f

#Libft library
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

# Source files directory
SRC_DIR = C

# Source files (.c)
SRC = $(SRC_DIR)/init.c $(SRC_DIR)/render.c $(SRC_DIR)/colors.c $(SRC_DIR)/mandelbrot.c $(SRC_DIR)/julia.c $(SRC_DIR)/utils.c $(SRC_DIR)/events.c

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

# Make the Libft library
$(LIBFT):
	make -C $(LIBFT_PATH)

# Create the final executable by linking object files and Libft
$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Default target to run / build the project
all: $(NAME)

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
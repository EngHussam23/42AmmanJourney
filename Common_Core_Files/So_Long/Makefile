# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:26:43 by halragga          #+#    #+#              #
#    Updated: 2025/12/01 17:52:49 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Excutable file:
NAME = so_long

# Flags:
CFLAGS = -Wall -Wextra -Werror
# -lmlx: MiniLibX library linking command; graphics lib, needed to open windows, draw pixels, create images, etc.
# -lX11: a library MiniLibX needs it to communicate with the display server.
# -lXext: X11 Extension library linking command; provides additional functionality for the X11 library, like image handling.
# -lm: Math library.
# -lz : Compression library.
MLX_FLAGS = -lmlx -lXext -lX11 -lm

#Compilation Command "Full":
CC = cc $(CFLAGS) $(MLX_FLAGS)

# Force Remove:
RM = rm -f

# Libft:
LIBFT_PATH = Libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

# Source Files:
SRC_DIR = C
SRCs = $(SRC_DIR)/cleanup.c $(SRC_DIR)/render.c $(SRC_DIR)/movement.c $(SRC_DIR)/parse.c

# Objects directory:
OBJ_DIR = Objects

# Objects:
# from (.c) to (.o):
OBJ = $(SRCs:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Initaite the compilation automation
all: $(NAME)

# Compile but don't re-link
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(CFLAGS) -c $< -o $@

# Libft make:
$(LIBFT_ARC):
	make -C $(LIBFT_PATH)

# Final compilation, where the linikng happens:
$(NAME): $(LIBFT_ARC) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_ARC) -o $(NAME)

# PROTECTION! in case the objects directory is not created:
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Objects level cleaning:
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean

# Ecutable & Archives cleaning + $(clean):
fclean:
	$(RM) $(OBJ) $(NAME)
	make -C $(LIBFT_PATH) fclean

# Recombile from scratch:
re: fclean all

# Phony
# This rule makes sure that the targets: {all clean fclean re} are always executed
.PHONY: all clean fclean re

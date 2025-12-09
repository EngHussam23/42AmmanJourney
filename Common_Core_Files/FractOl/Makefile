# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 09:58:17 by halragga          #+#    #+#              #
#    Updated: 2025/12/09 20:14:11 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Excutable file:
NAME = fractol

# Flags:
CFLAGS = -Wall -Wextra -Werror
# -lmlx: MiniLibX library linking command; graphics lib, needed to open windows, draw pixels, create images, etc.
# -lX11: a library MiniLibX needs it to communicate with the display server.
# -lXext: X11 Extension library linking command; provides additional functionality for the X11 library, like image handling.
# -lm: Math library.
# -lz : Compression library.
MLX_FLAGS = -lXext -lX11 -lmlx -lm

#Compilation Command "Full":
CC = cc

# Force Remove:
RM = rm -f

# Libft:
LIBFT_PATH = Libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

# Source Files:
SRC_DIR = C
SRCs = $(SRC_DIR)/main.c $(SRC_DIR)/events.c $(SRC_DIR)/init.c $(SRC_DIR)/render.c $(SRC_DIR)/fractals.c $(SRC_DIR)/colors.c

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
$(NAME): $(OBJ_DIR) $(LIBFT_ARC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libmlx_Linux.a $(LIBFT_ARC) $(MLX_FLAGS) -o $(NAME)

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

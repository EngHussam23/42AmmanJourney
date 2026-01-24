# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 09:58:17 by halragga          #+#    #+#              #
#    Updated: 2026/01/24 13:41:01 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Excutable file:
NAME = fractol

# Libft:
LIBFT_PATH = Libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

# mlx
MLX_PATH = minilibx-linux
MLX_ARC = minilibx-linux/libmlx_Linux.a

# Flags:
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_PATH) -I$(MLX_PATH)
# -lmlx: MiniLibX library linking command; graphics lib, needed to open windows, draw pixels, create images, etc.
# -lX11: a library MiniLibX needs it to communicate with the display server.
# -lXext: X11 Extension library linking command; provides additional functionality for the X11 library, like image handling.
# -lm: Math library.
MLX_FLAGS = -lXext -lX11 -lm

#Compilation Command "Full":
CC = cc

# Force Remove:
RM = rm -f


# Source Files:
SRC_DIR = C
SRCs =  $(SRC_DIR)/main.c \
		$(SRC_DIR)/colors.c \
		$(SRC_DIR)/events.c \
		$(SRC_DIR)/fractals.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/phoenix.c

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

$(MLX_ARC): $(MLX_PATH)
	make -C $(MLX_PATH)

$(MLX_PATH):
	git clone https://github.com/42paris/minilibx-linux

# Final compilation, where the linikng happens:
$(NAME): $(OBJ_DIR) $(LIBFT_ARC) $(MLX_ARC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -L$(MLX_PATH) -lft -lmlx_Linux $(MLX_FLAGS) -o $(NAME)

# PROTECTION! in case the objects directory is not created:
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Objects level cleaning:
clean:
	$(RM) -rf $(OBJ_DIR) $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

# Ecutable & Archives cleaning + $(clean):
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# Recombile from scratch:
re: fclean all

# Phony
# This rule makes sure that the targets: {all clean fclean re} are always executed
.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 09:58:17 by halragga          #+#    #+#              #
#    Updated: 2026/01/30 00:42:36 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Excutable file:
NAME = push_swap

# Libft:
LIBFT_PATH = Libft
LIBFT_ARC = $(LIBFT_PATH)/libft.a

# Flags:
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_PATH)

#Compilation Command "Full":
CC = cc

# Force Remove:
RM = rm -f


# Source Files:
SRC_DIR = c_files
SRCs =  $(SRC_DIR)/main.c \
		$(SRC_DIR)/ \
		$(SRC_DIR)/ \
		$(SRC_DIR)/ \
		$(SRC_DIR)/ \
		$(SRC_DIR)/ \
		$(SRC_DIR)/

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
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

# PROTECTION! in case the objects directory is not created:
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Objects level cleaning:
clean:
	$(RM) -rf $(OBJ_DIR) $(OBJ)
	make -C $(LIBFT_PATH) clean

# Ecutable & Archives cleaning + $(clean):
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# Recombile from scratch:
re: fclean all

# Phony
# This rule makes sure that the targets: {all clean fclean re} are always executed
.PHONY: all clean fclean re

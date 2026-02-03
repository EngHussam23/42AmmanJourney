# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 09:58:17 by halragga          #+#    #+#              #
#    Updated: 2026/02/02 20:46:39 by halragga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Excutable file name (./server or ./client):
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_SERVER_BONUS = client_bonus

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
SERVER_SRCs = $(SRC_DIR)/server_main.c
CLIENT_SRCs = $(SRC_DIR)/client_main.c
SERVER_BONUS_SRCs = $(SRC_DIR)/server_main.c
CLIENT_BONUS_SRCs = $(SRC_DIR)/client_main.c

# Objects directory (server):
SERVER_OBJ_DIR = server_objects
SERVER_OBJ_BONUS_DIR = server_bonus_objects

# Objects directory (client):
CLIENT_OBJ_DIR = client_objects
CLIENT_OBJ_BONUS_DIR = client_bonus_objects

# Objects:
# from (.c) to (.o):
# Server
SERVER_OBJ = $(SERVER_SRCs:$(SRC_DIR)/%.c=$(SERVER_OBJ_DIR)/%.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRCs:$(SRC_DIR)/%.c=$(SERVER_OBJ_BONUS_DIR)/%.o)
# Client
CLIENT_OBJ = $(CLIENT_SRCs:$(SRC_DIR)/%.c=$(CLIENT_OBJ_DIR)/%.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRCs:$(SRC_DIR)/%.c=$(CLIENT_OBJ_BONUS_DIR)/%.o)

##############################
#                            #
#   PROCESS STARTS HERE!!!   #
#                            #
##############################
# Initaite the compilation automation
all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

# Compile but don't re-link (server)
$(SERVER_OBJ_DIR)/server_main.o: $(SRC_DIR)/server_main.c
	cc $(CFLAGS) -c $< -o $@

# Compile but don't re-link (server-bonus)
$(SERVER_OBJ_BONUS_DIR)/server_main.o: $(SRC_DIR)/server_main_bonus.c
	cc $(CFLAGS) -c $< -o $@

# Compile but don't re-link (client)
$(CLIENT_OBJ_DIR)/client_main.o: $(SRC_DIR)/client_main.c
	cc $(CFLAGS) -c $< -o $@

# Compile but don't re-link (client-bonus)
$(CLIENT_OBJ_BONUS_DIR)/client_main.o: $(SRC_DIR)/client_main_bonus.c
	cc $(CFLAGS) -c $< -o $@

# Libft make:
$(LIBFT_ARC):
	make -C $(LIBFT_PATH)

# Final compilation, where the linikng happens (server):
$(NAME_SERVER): $(SERVER_OBJ_DIR) $(LIBFT_ARC) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_PATH) -lft -o $(NAME_SERVER)

# Final compilation, where the linikng happens (client):
$(NAME_CLIENT): $(CLIENT_OBJ_DIR) $(LIBFT_ARC) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_PATH) -lft -o $(NAME_CLIENT)

# Final compilation, where the linikng happens (server-bonus):
$(NAME_SERVER_BONUS): $(SERVER_OBJ_BONUS_DIR) $(LIBFT_ARC) $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -L$(LIBFT_PATH) -lft -o $(NAME_SERVER_BONUS)

# Final compilation, where the linikng happens (client):
$(NAME_CLIENT_BONUS): $(CLIENT_OBJ_BONUS_DIR) $(LIBFT_ARC) $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -L$(LIBFT_PATH) -lft -o $(NAME_CLIENT_BONUS)


# PROTECTION! in case the objects directory is not created:
$(SERVER_OBJ_DIR):
	mkdir -p $(SERVER_OBJ_DIR)

$(CLIENT_OBJ_DIR):
	mkdir -p $(CLIENT_OBJ_DIR)

$(SERVER_OBJ_BONUS_DIR):
	mkdir -p $(SERVER_OBJ_BONUS_DIR)

$(CLIENT_OBJ_BONUS_DIR):
	mkdir -p $(CLIENT_OBJ_BONUS_DIR)

# Objects level cleaning:
clean:
	$(RM) -rf $(SERVER_OBJ_DIR) $(SERVER_OBJ)
	$(RM) -rf $(CLIENT_OBJ_DIR) $(CLIENT_OBJ)
	$(RM) -rf $(SERVER_OBJ_BONUS_DIR) $(SERVER_OBJ)
	$(RM) -rf $(CLIENT_OBJ_BONUS_DIR) $(CLIENT_OBJ)
	make -C $(LIBFT_PATH) clean

# Ecutable & Archives cleaning + $(clean):
fclean: clean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_SERVER_BONUS)
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_CLIENT_BONUS)
	make -C $(LIBFT_PATH) fclean

# Recombile from scratch:
re: fclean all

# Phony
# This rule makes sure that the targets: {all clean fclean re} are always executed
.PHONY: all bonus clean fclean re

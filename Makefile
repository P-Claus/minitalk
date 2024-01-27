#########################################
###		 CONFIG	      	      ###
#########################################

CLIENT_NAME	= client
SERVER_NAME	= server
NAME		= $(CLIENT_NAME) $(SERVER_NAME)


LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a
LIBFT_SOURCES	= $(LIBFT_DIR)/*.c
LIBFT_OBJ	= $(LIBFT_DIR)/*.o

INCLUDES	= -I ./includes
CC		= cc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra $(INCLUDES)

SOURCES_DIR	= src/
SERVER_SRC	= $(SOURCES_DIR)server.c
CLIENT_SRC	= $(SOURCES_DIR)client.c

#########################################
###		 BONUS	      	      ###
#########################################
BONUS_CLIENT_NAME	= client_bonus
BONUS_SERVER_NAME	= server_bonus
BONUS_NAME		= $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

BONUS_INCLUDES		= -I ./bonus_includes
BONUS_SERVER_SRC	= $(SOURCES_DIR)server_bonus.c
BONUS_CLIENT_SRC	= $(SOURCES_DIR)client_bonus.c

#########################################
###		 COLORS	      	      ###
#########################################
GREEN		= \033[0;92m

#########################################
###		 RULES	      	      ###
#########################################

name: $(SERVER_NAME) $(CLIENT_NAME)
all: $(NAME)

$(LIBFT): 
	@make -C $(LIBFT_DIR) -s
	@echo "$(GREEN)Libft has been created!"

$(SERVER_NAME): $(LIBFT) $(SERVER_SRC) ./includes/server.h ./includes/minitalk.h
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(SERVER_NAME) $(SERVER_SRC) $(LIBFT)
	@echo "$(GREEN)The server has been created!"

$(CLIENT_NAME): $(LIBFT) $(CLIENT_SRC) ./includes/client.h ./includes/minitalk.h
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(CLIENT_NAME) $(CLIENT_SRC) $(LIBFT) 
	@echo "$(GREEN)The client has been created!"

clean:
	@make clean -C $(LIBFT_DIR) -s
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_OBJ) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)
	@echo "$(GREEN)The server, client and object files from libft have been removed!"

fclean:
	@make fclean -C $(LIBFT_DIR) -s
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_OBJ) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)
	@echo "$(GREEN)The server, client, libft and the object files have been removed!"

re:
	@make fclean
	@make

bonus: $(LIBFT) $(BONUS_SERVER_NAME) $(BONUS_CLIENT_NAME)

$(BONUS_SERVER_NAME): $(LIBFT) $(BONUS_SERVER_SRC) ./bonus_includes/server_bonus.h ./bonus_includes/minitalk_bonus.h
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -o $(BONUS_SERVER_NAME) $(BONUS_SERVER_SRC) $(LIBFT) 
	@echo "$(GREEN)The server with bonus has been created!"

$(BONUS_CLIENT_NAME): $(LIBFT) $(BONUS_CLIENT_SRC) ./bonus_includes/client_bonus.h ./bonus_includes/minitalk_bonus.h
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -o $(BONUS_CLIENT_NAME) $(BONUS_CLIENT_SRC) $(LIBFT) 
	@echo "$(GREEN)The client with bonus has been created!"



.PHONY:			all clean fclean re bonus

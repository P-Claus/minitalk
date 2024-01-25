#########################################
###		 CONFIG	      	      ###
#########################################

CLIENT_NAME	= client
SERVER_NAME	= server
NAME		= $(CLIENT_NAME) $(SERVER_NAME)


LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a
LIBFT_SOURCES	= libft/*.c
LIBFT_OBJ	= libft/*.o

INCLUDES	= -I ./includes
CC		= cc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra $(INCLUDES)

SOURCES_DIR	= src/
SERVER_SRC	= $(SOURCES_DIR)server.c
CLIENT_SRC	= $(SOURCES_DIR)client.c


#########################################
###		 COLORS	      	      ###
#########################################
GREEN		= \033[0;92m

#########################################
###		 RULES	      	      ###
#########################################

name: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)
all: $(NAME)

$(LIBFT): 
	@make -C $(LIBFT_DIR) -s
	@echo "$(GREEN)Libft has been created!"

$(SERVER_NAME): $(SERVER_SRC) ./includes/server.h ./includes/minitalk.h
	@$(CC) $(CFLAGS) $(INCLUDES) -L $(LIBFT_DIR) -o $(SERVER_NAME) $(SERVER_SRC) -lft
	@echo "$(GREEN)The server has been created!"

$(CLIENT_NAME): $(CLIENT_SRC) ./includes/client.h ./includes/minitalk.h
	@$(CC) $(CFLAGS) $(INCLUDES) -L $(LIBFT_DIR) -o $(CLIENT_NAME) $(CLIENT_SRC) -lft
	@echo "$(GREEN)The client has been created!"

clean:
	@make clean -C $(LIBFT_DIR) -s
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_OBJ)
	@echo "$(GREEN)The server, client and object files from libft have been removed!"

fclean:
	@make fclean -C $(LIBFT_DIR) -s
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_OBJ)
	@echo "$(GREEN)The server, client, libft and the object files have been removed!"

re:
	@make fclean
	@make

.PHONY:			all clean fclean re 

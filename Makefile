CLIENT_NAME = client

SERVER_NAME = server

LIBFT = libft

LIBFT_SOURCES = libft/*.c
LIBFT_OBJ = libft/*.o

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

SOURCES = server.c client.c 

OBJ_FILES = $(SOURCES:%.c=%.o)

#colours
GREEN = \033[0;92m

all: library $(SERVER_NAME) $(CLIENT_NAME) 

library:
	@make -C $(LIBFT) -s
	@echo "$(GREEN)Libft has been created!"

$(CLIENT_NAME): client.c
	@$(CC) $(CFLAGS) -o client client.c
	@echo "$(GREEN)The client has been created!"

$(SERVER_NAME): server.c
	@$(CC) $(CFLAGS) -o server server.c
	@echo "$(GREEN)The server has been created!"

clean:
	@make clean -C $(LIBFT) -s
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_OBJ)
	@echo "$(GREEN)The server, client and object files from libft have been removed!"

fclean:
	@make fclean -C $(LIBFT) -s
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT_OBJ)
	@echo "$(GREEN)The server, client, libft and the object files have been removed!"

re:
	make fclean
	make

.PHONY:			all clean fclean re library

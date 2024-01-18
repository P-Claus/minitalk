CLIENT_NAME = client

SERVER_NAME = server

LIBFT = libft.a

LIBFT_SOURCES = libft/*.c
LIBFT_OBJ = libft/*.o

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

SOURCES = server.c 

OBJ_FILES = $(SOURCES:%.c=%.o)

#colours
GREEN = \033[0;92m

all: $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT)

$(CLIENT_NAME): client.c
	@$(CC) $(CFLAGS) -o client client.c
	@echo "$(GREEN)The client has been created!"

$(SERVER_NAME): server.c
	@$(CC) $(CFLAGS) -o server server.c
	@echo "$(GREEN)The server has been created!"


clean:
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(LIBFT) $(LIBFT_OBJ)
	@echo "$(GREEN)The server and client have been removed!"

$(LIBFT): $(LIBFT_SOURCES)
	@cd libft && $(MAKE)

.PHONY:			all clean fclean re bonus

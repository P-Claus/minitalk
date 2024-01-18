CLIENT_NAME = client

SERVER_NAME = server

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

SOURCES = server.c 

OBJ_FILES = $(SOURCES:%.c=%.o)

#colours
GREEN = \033[0;92m

all: $(SERVER_NAME)

#$(CLIENT_NAME): client.c
#	$(CC) $(CFLAGS) -o client client.c

$(SERVER_NAME): server.c
	@$(CC) $(CFLAGS) -o server server.c
	@echo "$(GREEN)The server has been created!"


clean:
	@$(RM) $(SERVER_NAME)
	@echo "$(GREEN)The server and client have been removed!"

.PHONY:			all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:41:01 by pclaus            #+#    #+#              #
#    Updated: 2023/11/07 17:41:03 by pclaus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

SOURCES = *.c

OBJ_FILES = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES)
	@$(CC) $(CFLAGS) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJ_FILES)

clean:
	@$(RM) $(OBJ_FILES)

fclean: clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:			all clean fclean re bonus

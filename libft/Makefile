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

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_memcpy.c ft_strchr.c ft_isprint.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ_FILES = $(SOURCES:.c=.o)

BONUS_SOURCES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJ_FILES = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "making the library"
	cc $(CFLAGS) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJ_FILES)

clean:
	@rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re:	fclean $(NAME)

bonus: 
	@echo "making the library with the bonus"
	cc $(CFLAGS) -c $(SOURCES) $(BONUS_SOURCES)
	@ar rcs $(NAME) $(OBJ_FILES) $(BONUS_OBJ_FILES)

.PHONY:			all clean fclean re bonus

#########################################
###		CONFIG		      ###
#########################################

NAME		= libft.a

CFLAGS		= -Wall -Werror -Wextra
CC		= cc
RM		= rm -rf
MKDIR		= mkdir -p

SOURCES_DIR	= src
SOURCES		= $(wildcard $(SOURCES_DIR)/*.c)
OBJ		= $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))
OBJ_DIR		= obj

INCLUDES	= includes/*.h

#########################################
PRINTF_SRC_DIR	= printf
PRINTF_SRC	= $(wildcard $(PRINTF_SRC_DIR)/*.c)
PRINTF_OBJ	= $(addprefix $(OBJ_DIR)/, $(notdir $(PRINTF_SRC:.c=.o))) 


#########################################
###		COLORS		      ###
#########################################

RED		= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
RESET		= \033[0m
MOVEUP		= \033[F

#########################################
###		RULES		      ###
#########################################

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ)
	@ar rcs $(NAME) $(OBJ) $(PRINTF_OBJ)
	@echo "$(GREEN)Libft has been created!"

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $<"
	
$(OBJ_DIR)/%.o: $(PRINTF_SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $<"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)The object files from libft have been removed!"

fclean: 
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)The object files from libft and the library have been removed!"
	

re:
	@make fclean
	@make

.PHONY:			all clean fclean re 

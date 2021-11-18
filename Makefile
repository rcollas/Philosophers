NAME		= philosophers

SRC_FILES	= main.c\
			  utils.c\
			  check.c\

OBJS_DIR	= objs

SRC_DIR		= src

INCLUDE		= ./include

SRC_OBJS	= $($(SRC_DIR)/SRC_FILES:.c=.o)

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE) -g

RM			= rm -rf

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
			@$(CC) -c $(CFLAGS) $< -o $@


all:		$(NAME)

$(NAME):	$(SRC_OBJS)
				@$(CC) $(CFLAGS) $(OBJS_DIR)$(SRC_OBJS) -o $(NAME)
				@echo "$(NAME) created"

clean:
			@$(RM) $(SRC_OBJS)
			@echo "$(NAME) .o deleted"

fclean:		clean
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:		all clean fclean re
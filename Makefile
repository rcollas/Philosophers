NAME		= philosophers

SRC_FILES	= main.c\
			  utils.c\
			  check.c\
			  init.c\
			  error.c\
			  mutex.c\
			  thread.c\

OBJS_DIR	= objs

SRC_DIR		= src

INCLUDE		= ./include

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE) -g -pthread

RM			= rm -rf

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
			@$(CC) $(CFLAGS) -c $< -o $@


all:		$(NAME)

$(NAME):	$(OBJS)
				@$(CC) $(CFLAGS) -o $@ $^
				@echo "$(NAME) created"

clean:
			@$(RM) $(OBJS)
			@echo "$(NAME) .o deleted"

fclean:		clean
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:		all clean fclean re
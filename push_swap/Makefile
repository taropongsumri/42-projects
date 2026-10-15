NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I src -I ft_printf

SRC_DIRS	= src func utils ft_printf
OBJ_DIR		= obj

SRCS		= $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

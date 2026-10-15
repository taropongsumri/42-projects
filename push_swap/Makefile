NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I src -I ft_printf

OBJ_DIR		= obj

SRCS		= src/push_swap.c \
			  func/main_operations.c func/push_core.c \
			  func/push_operations.c func/reverse_operations.c \
			  func/rotate_operations.c func/swap_operations.c \
			  sort/ft_sort.c sort/ft_sort_small.c sort/ft_move_utils.c \
			  sort/ft_sort_simple.c sort/ft_sort_medium.c \
			  sort/ft_sort_complex.c \
			  utils/ft_atoi.c utils/ft_bench.c utils/ft_disorder.c \
			  utils/ft_error.c utils/ft_flags.c utils/ft_index.c \
			  utils/ft_isdigit.c utils/ft_isnum.c utils/ft_node.c \
			  utils/ft_parse_args.c utils/ft_split.c \
			  utils/ft_stack_utils.c utils/ft_str_utils.c \
			  ft_printf/ft_out.c ft_printf/ft_printf.c \
			  ft_printf/ft_putchar_print.c ft_printf/ft_putnbr_print.c \
			  ft_printf/ft_putptr_print.c ft_printf/ft_putstr_print.c \
			  ft_printf/ft_putun_print.c ft_printf/ft_putx_print.c \
			  ft_printf/ft_strlen.c

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

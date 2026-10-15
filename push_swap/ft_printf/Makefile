NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC = ft_printf.c \
	ft_out.c \
	ft_putchar_print.c \
	ft_putstr_print.c \
	ft_putnbr_print.c \
	ft_putptr_print.c \
	ft_putun_print.c \
	ft_putx_print.c \
	ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

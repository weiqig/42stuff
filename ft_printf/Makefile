# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgan <wgan@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 15:45:33 by wgan              #+#    #+#              #
#    Updated: 2025/11/03 15:45:34 by wgan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -g3

AR = ar rcs

SRC =	ft_printf.c \
		src/ft_strlen.c \
		src/ft_putchar.c \
		src/ft_putstr.c \
		src/ft_putnbr_base.c \
		src/ft_print_char.c \
		src/ft_print_str.c \
		src/ft_print_ptr.c \
		src/ft_print_decimal.c \
		src/ft_print_integer.c \
		src/ft_print_unsigned.c \
		src/ft_print_hexl.c \
		src/ft_print_hexu.c \
		src/ft_print_percent.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

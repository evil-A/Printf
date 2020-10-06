# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 07:50:45 by evila-ro          #+#    #+#              #
#    Updated: 2020/02/14 19:32:54 by evila-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #ME

NAME	= libftprintf.a


SRC	=	ft_printf.c		ft_printf_utils.c	ft_string.c		\
		ft_stringb.c	ft_intera.c		ft_interb.c			\
		ft_unsign.c		ft_hex.c		ft_hexx.c			\
		ft_pointer.c	ft_per.c		ft_char.c			\
		ft_itoas.c		ft_lens.c

CFLAGS = -Wall -Werror -Wextra -I

OBJ	= $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(SRC) libftprintf.h
	@gcc $(CFLAGS)./ -c $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c $< -o $@

clean:
	@rm -f *.o
	@rm -f *.out

fclean: clean
	@rm -f  $(NAME)

re:  fclean all
.PHONY: all clean fclean re

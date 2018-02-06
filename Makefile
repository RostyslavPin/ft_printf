#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpin <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:49:42 by rpin              #+#    #+#              #
#    Updated: 2017/11/08 18:50:51 by rpin             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

HEADER = ./include/

FLAG = -Wall -Wextra -Werror

OPTION = -c -I $(HEADER)

SRC = ./src/ft_bzero.c ./src/ft_isdigit.c \
	  ./src/ft_atoi.c ./src/ft_memset.c ./src/ft_isdigit.c\
	  ./src/ft_itoa.c ./src/ft_printf.c ./src/ft_putchar.c\
	  ./src/ft_putstr.c ./src/ft_putchar_unicode.c ./src/ft_strlen.c\
	  ./src/ft_strnew.c ./src/ft_putnbr.c

OBJ = ft_bzero.o ft_isdigit.o \
	  ft_atoi.o ft_memset.o ft_isdigit.o\
	  ft_itoa.o ft_printf.o ft_putchar.o\
	  ft_putstr.o ft_putchar_unicode.o ft_strlen.o\
	  ft_strnew.o ft_putnbr.o

all: $(NAME)

$(NAME):
	@ gcc $(FLAG) $(OPTION) $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean: 
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
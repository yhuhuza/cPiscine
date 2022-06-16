# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeter <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 14:38:33 by vmeter            #+#    #+#              #
#    Updated: 2021/07/19 13:32:04 by vmeter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRC:.c=.o}

NAME = libft.a

CC = gcc

LIBC = ar src

LIBR = ranlib

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

IN = includes

all: 	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${IN}	

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	 ${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re



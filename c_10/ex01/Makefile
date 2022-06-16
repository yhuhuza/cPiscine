# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeter <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 10:37:24 by vmeter            #+#    #+#              #
#    Updated: 2021/07/20 10:37:29 by vmeter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_cat.c ft_putstr.c ft_putchar.c

NAME = ft_cat

CC = gcc

CFLAGC = -Wall -Wextra -Werror

HEAD = ft.h

RM = rm -f

all: 	
	${CC} ${CFLAGC} ${SRC} -o ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re

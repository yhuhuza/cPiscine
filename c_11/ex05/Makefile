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

SRC = do-op.c ft_atoi.c ft_putchar.c ft_putnbr.c

NAME = do_op

CC = gcc

CFLAGC = -Wall -Wextra -Werror

RM = rm -f

all: 	
	${CC} ${CFLAGC} ${SRC} -o ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re

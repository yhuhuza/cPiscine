# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeter <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 17:30:42 by vmeter            #+#    #+#              #
#    Updated: 2021/07/19 17:38:47 by vmeter           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_display_file.c ft_putstr.c ft_putchar.c

NAME = ft_display_file

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


NAME = bsq
CC = gcc
OFLAGS =  -Wall -Wextra -Werror -I ${HEADER} 
HEADER = include
SRCS = src
OBJ = obj
RM = rm -rf
BUFFER = buffer_file
HDRS = $(wildcard $(HEADER)/*.h)
SRC = $(wildcard $(SRCS)/*.c)
OBJS = $(patsubst $(SRCS)/%.c, $(OBJ)/%.o, $(SRC))

all: ${NAME}
	
${NAME}:	${HDRS} ${OBJS}
	${CC} ${OFLAGS} ${OBJS} -o ${NAME}  

${OBJ}/%.o: ${SRCS}/%.c
	mkdir -p ${OBJ}
	${CC} ${OFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}
	${RM} ${NAME}

fclean: clean
	${RM} ${NAME}
	${RM} ${OBJ}
	${RM} ${BUFFER}
	
re: fclean all

.PHONY : clean fclean re


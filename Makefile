SRC			=	get_next_line.c \
				get_next_line_utils.c

OBJ			=	${SRC:.c=.o}

NAME		=	gnl.a

CC			=	gcc -c

AR			=	ar rc

RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} $<	-o ${<:.c=.o}

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

BIN			=	bin/
DEV-FLAGS	= -Wall -Wextra
FLAGS		= ${DEV-FLAGS} -Werror
CC			= gcc
COMPILE.C	= ${CC} ${FLAGS}
DEV_COMPILE = ${CC} ${DEV-FLAGS} ${INCLUDE}
NAME		= libftprintf.a
AR			= ar -rcs

all: ${NAME}

${NAME}: ${OBJS}
	@	$(AR) ${NAME} ${OBJS}
	@	echo "Succesfully created ${NAME}"

clean:
	@	${RM} ${OBJS} *.o a.out
	@	echo "Succesfully deleted objects"

fclean:	clean
	@	${RM} ${NAME}
	@	echo "Succesfully deleted library"

re: fclean all

.PHONY: clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 11:56:47 by izarate-          #+#    #+#              #
#    Updated: 2023/03/08 14:36:24 by izarate-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN			=	bin/
DEV-FLAGS	= -Wall -Wextra
FLAGS		= ${DEV-FLAGS} -Werror
CC			= gcc
COMPILE.C	= ${CC} ${FLAGS}
DEV_COMPILE = ${CC} ${DEV-FLAGS} ${INCLUDE}
NAME		= libftprintf.a
AR			= ar -rcs

SRC	=	ft_printf.c 	\
		utils_printf.c	\
		print_base.c
all: ${NAME}

${NAME}: ${OBJS}
	@	$(AR) ${NAME} ${OBJS}
	@	echo "Succesfully created ${NAME}"

${BIN}%.o: %.c
	@	mkdir -p bin
	@	echo "$< OK"
	@	${COMPILE.C} -c $< -o $@

clean:
	@	${RM} ${OBJS} *.o a.out
	@	echo "Succesfully deleted objects"

fclean:	clean
	@	${RM} ${NAME}
	@	echo "Succesfully deleted library"

re: fclean all

.PHONY: clean fclean re

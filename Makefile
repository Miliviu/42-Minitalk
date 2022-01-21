# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhagon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:51:46 by juhagon           #+#    #+#              #
#    Updated: 2021/12/15 14:29:34 by juhagon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS1 = server.c 
SRCS2 = client.c aux.c

OBJS1 = ${SRCS1:.c=.o}
OBJS2 = ${SRCS2:.c=.o}

SERVER = server
CLIENT = client

GCC   = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f


.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

compile: ${SERVER} ${CLIENT}

${SERVER}:	${OBJS1}
	${GCC} $(OBJS1) -o ${SERVER}

${CLIENT}: ${OBJS2}
	${GCC} $(OBJS2) -o ${CLIENT}

all:	${SERVER} ${CLIENT}
clean:
	${RM} ${OBJS1} ${OBJS2}

fclean:		clean
	${RM} ${SERVER} ${CLIENT}

re: fclean all

.PHONY:		all clean fclean re compile

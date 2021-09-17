# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:41:47 by goliano-          #+#    #+#              #
#    Updated: 2021/09/17 15:55:08 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./utils/param_checker.c ./srcs/push_swap.c ./utils/ft_strcmp.c \
	   ./utils/ft_atoi.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = cc
rm = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm ${OBJS}

fclean: clean
	${RM} ${NAME}


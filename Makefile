# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:41:47 by goliano-          #+#    #+#              #
#    Updated: 2021/09/21 16:37:14 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./utils/ft_latoi.c ./srcs/push_swap.c ./utils/ft_strcmp.c \
	    ./srcs/param_checker.c ./srcs/init_stacks.c ./utils/ft_calloc.c \
	   ./actions/s_actions.c ./actions/r_actions.c ./utils/ft_memset.c \
	   ./actions/p_actions.c ./actions/rr_actions.c ./utils/ft_memcpy.c \
	   ./sort_algorithm/short_sort.c ./sort_algorithm/mp_algorithm_a.c \
	./sort_algorithm/sort_n_stack.c ./sort_algorithm/mp_algorithm_b.c \
	./sort_algorithm/handle_chunks.c ./utils/ft_split.c
	
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


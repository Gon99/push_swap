# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:41:47 by goliano-          #+#    #+#              #
#    Updated: 2021/10/25 18:45:49 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g

SRCS = ./utils/ft_latoi.c ./srcs/push_swap.c ./utils/ft_strcmp.c \
	./srcs/param_checker.c ./srcs/init_stacks.c ./utils/ft_calloc.c \
	./actions/s_actions.c ./actions/r_actions.c ./utils/ft_memset.c \
	./actions/p_actions.c ./actions/rr_actions.c ./utils/ft_memcpy.c \
	./sort_algorithm/short_sort.c ./sort_algorithm/mp_algorithm_a.c \
	./sort_algorithm/sort_n_stack.c ./sort_algorithm/mp_algorithm_b.c \
	./utils/ft_split.c ./utils/ft_strlen.c ./free/free.c \
	./sort_algorithm/big_sort.c

OBJS = $(SRCS:.c=.o)

RM	= rm -f

NAME	= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS)	-o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

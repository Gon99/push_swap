/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:46:16 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/28 13:26:10 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(int argc, char **argv, t_stack *n_stack)
{
	int	i;
	size_t	x;

	i = 1;
	x = 0;
	n_stack->stack_a = ft_calloc(argc - 1, sizeof(int));
	n_stack->stack_b = ft_calloc(argc - 1, sizeof(int));
	if (!n_stack->stack_a || !n_stack->stack_b)
		return ;
	n_stack->l_a = argc - 1;
	n_stack->l_b = 0;
	while (i < argc)
		n_stack->stack_a[x++] = ft_atoi(argv[i++]);
}

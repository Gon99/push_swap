/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:46:16 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/13 16:28:24 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(int argc, char **argv, t_stack *n_stack, t_sstack *s_stack)
{
	int		i;
	size_t	x;

	i = 1;
	x = 0;
	n_stack->stack_a = ft_calloc(argc - 1, sizeof(int));
	n_stack->stack_b = ft_calloc(argc - 1, sizeof(int));
	s_stack->ss = ft_calloc(argc - 1, sizeof(int));
	if (!n_stack->stack_a || !n_stack->stack_b)
		return ;
	n_stack->l_a = argc - 1;
    n_stack->l_b = 0;
	s_stack->l = argc - 1;
	while (i < argc)
	{
		n_stack->stack_a[x] = ft_latoi(argv[i]);
		s_stack->ss[x] = ft_latoi(argv[i]);
		x++;
		i++;
	}
}

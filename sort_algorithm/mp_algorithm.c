/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:57:19 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/30 19:03:29 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	a_is_sorted(t_stack *n_stack)
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < n_stack->l_a - 1 && is_sorted == 1)
	{
		if (n_stack->stack_a[i] > n_stack->stack_a[i + 1])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}

void	mp_algorithm(t_stack *n_stack, ts_stack *s_stack)
{
	int	hl;
	int	i;

	hl = n_stack->l_a / 2;
	i = 0;
	if (a_is_sorted(n_stack))
		return ;
	while (i < hl)
	{
		if (n_stack->stack_a[i] < s_stack->ss[hl])
			do_pb(n_stack);
		else
		{
			printf("ROMPE1\n");
			break;
		}
		i++;
	}
	i = 0;
	while (n_stack->l_b < hl)
	{
		if (n_stack->stack_a[n_stack->l_a - 1] < s_stack->ss[hl])
		{
			do_rra(n_stack);
			do_pb(n_stack);
		}
		else
			do_rra(n_stack);
		i++;
	}
}

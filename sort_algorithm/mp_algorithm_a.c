/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:57:19 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/04 11:45:43 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	a_is_sorted(t_stack *n_stack)
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

static void	do_first_half(t_stack *n_stack, ts_stack *s_stack, int hl, int *na)
{
	while (n_stack->stack_a[0] < s_stack->ss[hl])
	{
		*na = *na + 1;
		do_pb(n_stack);
	}
}

static void	do_second_half(t_stack *n_stack, ts_stack *s_stack, int hl, int *na)
{
	while (n_stack->stack_a[n_stack->l_a - 1] < s_stack->ss[hl])
	{
		*na = *na + 1;
		do_rra(n_stack);
		do_pb(n_stack);	
	}
	while (*na < hl)
	{
		if (n_stack->stack_a[0] < s_stack->ss[hl])
		{
			*na = *na + 1;
			do_pb(n_stack);
		}
		else
			do_ra(n_stack);
	}
    // fuera del while ultima ordenacion sa con dos numeros
	//if (n_stack->stack_a[0] > n_stack->stack_a[1])
		//do_sa(n_stack);
}

void	mp_algorithm_a(t_stack *n_stack, ts_stack *s_stack)
{
	int	hl;
	int	na;

	hl = n_stack->l_a / 2;
	na = 0;
	if (a_is_sorted(n_stack))
		return ;
	do_first_half(n_stack, s_stack, hl, &na);
	do_second_half(n_stack, s_stack, hl, &na);
}

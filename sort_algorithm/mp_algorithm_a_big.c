/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm_a_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:30:58 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/19 17:02:12 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_val_of_a(t_stack *n_stack)
{
	int	max;
	int	i;

	i = 1;
	max = n_stack->stack_a[0];
	while (i < n_stack->l_a)
	{
		if (n_stack->stack_a[i] > max)
			max = n_stack->stack_a[i];
		i++;
	}
	return (max);
}

static int	idx_of_max_val_of_a(t_stack *n_stack)
{
	int	i;
	int	idx;
	int	max;

	max = n_stack->stack_a[0];
	i = 1;
	idx = 0;
	while (i < n_stack->l_a)
	{
		if (n_stack->stack_a[i] > max)
		{
			max = n_stack->stack_a[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

static void	push_bigger_to_a(t_stack *n_stack, int na)
{
	int	idx;
	int	max;

	idx = idx_of_max_val_of_a(n_stack);
	max = get_max_val_of_a(n_stack);
	if (idx < n_stack->l_a / 2)
	{
		if (n_stack->stack_a[0] == max)
		{
			do_pb(n_stack);
			na--;
		}
		else
			do_ra(n_stack);
	}
	else
	{
		if (n_stack->stack_a[n_stack->l_a] == max)
		{
			na--;
			do_rra(n_stack);
			do_pb(n_stack);
		}
		else
			do_rra(n_stack);
	}
}

void	mp_algorithm_a_big(t_stack *n_stack, t_sstack *s_stack)
{
	int	idx;
	int	na;
	
	// pueden ser mas
	na = n_stack->l_a - (n_stack->l_a / 4);
	printf("NA: %d\n", na);
	idx = n_stack->l_a - na;
	while (na > 0)
	{
		while (n_stack->stack_a[0] > s_stack->ss[idx])
		{
			do_pb(n_stack);
			na--;
		}
		while (n_stack->stack_a[n_stack->l_a - 1] > s_stack->ss[idx])
		{
			do_rra(n_stack);
			do_pb(n_stack);
			na--;
		}
		push_bigger_to_a(n_stack, na);
	}
}

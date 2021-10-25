/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_algorithm_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:55:14 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/25 16:38:11 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	b_is_sorted(t_stack *n_stack)
{
	size_t	i;
	int		is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < n_stack->l_b - 1 && is_sorted == 1)
	{
		if (n_stack->stack_b[i] < n_stack->stack_b[i + 1])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}

static int	get_max_val_of_chunk(t_stack *n_stack)
{
	int		max;
	size_t	i;

	max = n_stack->stack_b[0];
	i = 1;
	while (i < n_stack->l_b)
	{
		if (n_stack->stack_b[i] > max)
			max = n_stack->stack_b[i];
		i++;
	}
	return (max);
}

static int	idx_of_max_val(t_stack *n_stack)
{
	size_t	i;
	int		idx;
	int		max;

	max = n_stack->stack_b[0];
	i = 1;
	idx = 0;
	while (i < n_stack->l_b)
	{
		if (n_stack->stack_b[i] > max)
		{
			max = n_stack->stack_b[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

static void	get_back_nums(t_stack *n_stack, int max)
{
	while (1)
	{
		if (n_stack->stack_b[n_stack->l_b - 1] == max)
		{
			do_rrb(n_stack);
			do_pa(n_stack);
			break ;
		}
		else
			do_rrb(n_stack);
	}
}

void	mp_algorithm_b(t_stack *n_stack)
{
	int		max;
	size_t	idx;

	while (n_stack->l_b > 0)
	{
		idx = idx_of_max_val(n_stack);
		max = get_max_val_of_chunk(n_stack);
		if (idx < n_stack->l_b / 2)
		{
			while (1)
			{
				if (n_stack->stack_b[0] == max)
				{
					do_pa(n_stack);
					break ;
				}
				else
					do_rb(n_stack);
			}
		}
		else
			get_back_nums(n_stack, max);
	}
}

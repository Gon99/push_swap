/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:19:48 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/29 17:08:22 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *n_stack)
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

void	three_sort(t_stack *n_stack)
{
	int	i;

	i = 0;
	while (i < n_stack->l_a - 1)
	{
		if (is_sorted(n_stack))
			break ;
		if (n_stack->stack_a[i] < n_stack->stack_a[i + 1] && \
				n_stack->stack_a[i] > n_stack->stack_a[n_stack->l_a - 1])
			do_rra(n_stack);
		else if(n_stack->stack_a[i] > n_stack->stack_a[i + 1] && \
				n_stack->stack_a[i] > n_stack->stack_a[n_stack->l_a - 1])
			do_ra(n_stack);
		else
		{
			do_sa(n_stack);
			i = -1;
		}
		i++;
	}
}

void	short_four(t_stack *n_stack)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (is_sorted(n_stack))
			break ;
		if (n_stack->stack_a[0] > n_stack->stack_a[1] && n_stack->stack_a[0] < n_stack->stack_a[n_stack->l_a - 1])
			do_rra(n_stack);
		else if(n_stack->stack_a[0] > n_stack->stack_a[n_stack->l_a - 1] && n_stack->stack_a[0] < n_stack->stack_a[1])
			do_ra(n_stack);
		else if(n_stack->stack_a[0] > n_stack->stack_a[1] /* && n_stack->stack_a[1] > n_stack->stack_a[2]*/)
			do_sa(n_stack);
		i++;
	}
	if (!is_sorted(n_stack))
		do_ra(n_stack);
}

void	short_sort(t_stack *n_stack)
{
	if (is_sorted(n_stack))
		return ;
	while (n_stack->l_a > 3)
		do_pb(n_stack);
	three_sort(n_stack);
	if (n_stack->l_b > 0)
		do_pa(n_stack);
	short_four(n_stack);
	if (n_stack->l_b > 0)
		do_pa(n_stack);
	//do_ra(n_stack);
	//do_pa(n_stack);
}

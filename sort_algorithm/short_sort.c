/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:19:48 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/22 16:08:22 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack *n_stack)
{
	size_t	i;

	i = 0;
	while (i < n_stack->l_a - 1)
	{
		if (a_is_sorted(n_stack))
			break ;
		if (n_stack->stack_a[i] < n_stack->stack_a[i + 1] && \
				n_stack->stack_a[i] > n_stack->stack_a[n_stack->l_a - 1])
			do_rra(n_stack);
		else if (n_stack->stack_a[i] > n_stack->stack_a[i + 1] && \
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

void	short_sort(t_stack *n_stack)
{
	if (a_is_sorted(n_stack))
		return ;
	three_sort(n_stack);
}

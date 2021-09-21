/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:42:38 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:32 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_ra(t_stack *n_stack)
{
	int	aux;
	int	i;

	write(1, "ra\n", 3);
	i = 0;
	aux = n_stack->stack_a[0];
	while (i < n_stack->l - 1)
	{
		n_stack->stack_a[i] = n_stack->stack_a[i + 1];
		i++;
	}
	n_stack->stack_a[n_stack->l - 1] = aux;
}

void	do_rb(t_stack *n_stack)
{
	int	aux;
	int	i;
	int	l;

	write(1, "rb\n", 3);
	i = 0;
	l = sizeof(n_stack->stack_b[0]) / sizeof(int);
	aux = n_stack->stack_b[0];
	while (i < l - 1)
	{
		n_stack->stack_b[i] = n_stack->stack_b[i + 1];
		i++;
	}
	n_stack->stack_b[i] = aux;
}

void	do_rr(t_stack *n_stack)
{
	do_ra(n_stack);
	do_rb(n_stack);
}

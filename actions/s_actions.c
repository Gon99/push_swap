/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:01:45 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/23 12:25:28 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_sa(t_stack *n_stack)
{
	int	aux;

	write(1, "sa\n", 3);
	aux = n_stack->stack_a[0];
	n_stack->stack_a[0] = n_stack->stack_a[1];
	n_stack->stack_a[1] = aux;
}

void	do_sb(t_stack *n_stack)
{
	int	aux;

	write(1, "sb\n", 3);
	aux = n_stack->stack_b[0];
	n_stack->stack_b[0] = n_stack->stack_b[1];
	n_stack->stack_b[1] = aux;
}

void	do_ss(t_stack *n_stack)
{
	do_sa(n_stack);
	do_sb(n_stack);
}

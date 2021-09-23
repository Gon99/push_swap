/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/23 14:32:46 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_pa(t_stack *n_stack)
{
	int	i;
	int	aux;
	int	aux2;

	i = 1;
	aux = n_stack->stack_a[0];
	n_stack->stack_a[0] = n_stack->stack_b[0];
	while (i < n_stack->l_a)
	{
		aux2 = n_stack->stack_a[i];
		if (i == 1)
			n_stack->stack_a[i] = aux;
		else
			n_stack->stack_a[i] = aux2;
		i++;
	}
	n_stack->l_a++;
}

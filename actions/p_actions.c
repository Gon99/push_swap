/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/21 16:57:37 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_pa(t_stack *n_stack)
{
	int	i;
	size_t	l;

	i = 0;
	l = sizeof(n_stack->stack_a) / sizeof(n_stack->stack_a[0]);
	printf("L: %zu\n", l);
	//n_stack->stack_a[0] = n_stack->stack_b[0];
}

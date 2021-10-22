/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:59:03 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/22 15:50:20 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_stack *n_stack, t_sstack *s_stack)
{
	free(n_stack->stack_a);
	free(n_stack->stack_b);
	free(s_stack->ss);
}

void	free_sp(char **sp)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (sp[l])
		l++;
	while (i < l)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

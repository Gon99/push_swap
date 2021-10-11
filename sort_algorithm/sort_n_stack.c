/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:26 by goliano-          #+#    #+#             */
/*   Updated: 2021/10/01 16:25:14 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_n_stack(t_sstack *s_stack)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < s_stack->l - 1)
	{
		j = i + 1;
		while (j < s_stack->l)
		{
			if (s_stack->ss[i] > s_stack->ss[j])
			{
				aux = s_stack->ss[i];
				s_stack->ss[i] = s_stack->ss[j];
				s_stack->ss[j] = aux;
			}
			j++;
		}
		i++;
	}
}
